// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include <stdio.h>
#include <pico/stdlib.h>
#include <IoConfig.h>
#include <PeripheralController.h>
#include <LedController.h>
#include <UnitTest.h>
#include <UnitDemo.h>
#include "XtBus.h"

static const uint32_t SYSTEM_CLOCK_KHZ = 125000;

static void Intialize()
{
    // We run this as early as possible just in case some output is driving something
    // in some way that it should not.  
    IoConfig::PreInitialzieIo();

    stdio_init_all();

    // Ensure we are using a consistent system clock even if SDK or 
    // bootloader changes the default.
    set_sys_clock_khz(SYSTEM_CLOCK_KHZ, true); 

    IoConfig::FinishInitializeIo();

    PeripheralController::instance.Initialize();
    LedController::instance.Initialize();

    // Allow time to connect USB serial monitor.
    for (int i = 0; i < 6; i++)
    {
        printf("Waiting...\n");
        sleep_ms(500);
    }

    XtBus::instance.Initialize();
}

static void RunTests()
{
    //while (true)
    {
        UnitTest::RunAllTests();
    }

    UnitDemo::RunLedControllerLedDemo();
    //UnitDemo::RunPerphieralControllerButtonDemo();
}


#include <pico/multicore.h>
#include "hardware/pio.h"
#include "hardware/regs/pio.h"
#include "hardware/regs/addressmap.h"


#define __scratch_x_func(func_name) __scratch_x(__STRING(func_name)) func_name

extern "C"
{
    volatile uint __scratch_x_func(loopCount);
    extern void SecondCorePollingLoop();
    extern int SimpleFunc();

    __attribute__ ((noinline)) int __scratch_x_func(SimpleRef)()
    {
        return 1;
    }

    void __scratch_x_func(SecondCorePollingLoopCRef)()
    {
        static const uint32_t sm = 0;

        // Just a mock up of what the tight polling loop needs to do.

        while(1)
        {
            sio_hw->fifo_wr = 0; // Write to FIFO so other CPU can count the number of loops.

            if (pio0->intr & (PIO_INTR_SM0_BITS | PIO_INTR_SM1_BITS))
            {
                pio0->intr = 0;
                continue;
            }

            if (pio1->intr & (PIO_INTR_SM0_BITS))
            {
                pio1->intr = 0;
                continue;
            }
    
            if (pio0->fstat &  (1u << (PIO_FSTAT_RXEMPTY_LSB + sm)))
            {
                pio_sm_get(pio0, 0);
                continue;
            }

            if (sio_hw->fifo_st & SIO_FIFO_ST_VLD_BITS)
            {
                (void)sio_hw->fifo_rd;
            }
        }
    }
}

void MulticoreExperiment()
{

    // Test second core.
    {
        // Allow time to connect USB serial monitor.
        for (int i = 0; i < 6; i++)
        {
            printf("Waiting...\n");
            sleep_ms(500);
        }

        printf("SecondCorePollingLoop() address: %08X\n", (uint)SecondCorePollingLoop);

    	multicore_launch_core1(SecondCorePollingLoop);
    	//multicore_launch_core1(SecondCorePollingLoopCRef);

        // This timing loop can measure a minimum of 8 cycles.
        while(1)
        {
            static const uint32_t loopCount = 10 * 1000 * 1000;

            uint64_t startTime = time_us_64();

            for (int count = loopCount; count; count--)
            {
                while (!multicore_fifo_rvalid())
                {
                    tight_loop_contents();
                }
                (void)sio_hw->fifo_rd;
            }

            uint64_t endTime = time_us_64();

            double cyclesPerLoop = (double)((endTime - startTime) * 125) / loopCount;

            printf ("Cycles per loop: %.2f\n", cyclesPerLoop);
        }
    }

}

int main()
{
    Intialize();

    // RunTests();


    // TEST CODE:
    pio_sm_put_blocking(pio1, 0, ~0x89ABCDEF);

    while(1)
    {
        if (pio_interrupt_get(pio0, 0))
        {
            pio_interrupt_clear(pio0, 0);
            printf("Write to reset IO address.\n");
        }
        if (pio_interrupt_get(pio0, 1))
        {
            pio_interrupt_clear(pio0, 1);
            printf("Write to select IO address.\n");
        }

        if (pio_interrupt_get(pio1, 0))
        {
            pio_interrupt_clear(pio1, 0);
            printf("Read from 322.\n");
        }


        if (pio_interrupt_get(pio1, 1))
        {
            pio_interrupt_clear(pio1, 1);
            printf("Read from 321.\n");
        }        

        if (pio_interrupt_get(pio1, 2))
        {
            pio_interrupt_clear(pio1, 2);
            printf("set_pindirs: Read ended.\n");
        }        

        if (pio_interrupt_get(pio1, 3))
        {
            pio_interrupt_clear(pio1, 3);
            printf("set_pindirs: Read active.\n");
        }                

//            if (pio1->irq & (PIO_INTR_SM0_BITS))
//            {
//                pio1->irq = 0;
//                printf("pio1 intr.\n");
//                continue;
//            }

        if (!(pio0->fstat &  (1u << (PIO_FSTAT_RXEMPTY_LSB + WRITE_CONTROL_REGISTER_SM))))
        {
            uint32_t rawData = pio_sm_get(pio0, 0);
            uint32_t address = 0x320 + ((rawData >> 10) & 0x3);
            uint32_t data = rawData & 0xFF;

            printf("Write to register %Xh, data: %02Xh\n", address, data);
        }

        if (!(pio1->fstat &  (1u << (PIO_FSTAT_RXEMPTY_LSB + WRITE_CONTROL_REGISTER_SM))))
        {
            uint32_t rawData = pio_sm_get(pio1, 0);

            printf("Read returned %08Xh\n", rawData);
        }        
    }


    return 0;
}
