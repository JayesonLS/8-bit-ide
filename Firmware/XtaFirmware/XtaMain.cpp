// Copyright (C) 2021 Titanium Studios Pty Ltd 
// 
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.If not, see < https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <pico/stdlib.h>
#include <IoConfig.h>
#include <PeripheralController.h>
#include <LedController.h>
#include <UnitTest.h>
#include <UnitDemo.h>


#include <pico/multicore.h>
#include "hardware/pio.h"


static void Intialize()
{
    // We run this as early as possible just in case some output is driving something
    // in some way that it should not.  
    IoConfig::PreInitialzieIo();

    stdio_init_all();

    PeripheralController::instance.Initialize();
    LedController::instance.Initialize();
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
        uint count = 0;
        uint32_t regValue;

        // Just a mock up of what the tight polling loop needs to do.

        while(1)
        {
            count++;
            loopCount = count;

            regValue = pio0->intr;
            if (regValue & (PIO_INTR_SM0_BITS | PIO_INTR_SM1_BITS))
            {
                goto pio0intr;
            }
            for (int i = 0 ; i < 1000; i++ )
            {
                
            }
        
            regValue = pio1->intr;
            if (regValue & (PIO_INTR_SM0_BITS))
            {
                goto pio1intr;
            }

            for (int i = 0 ; i < 1000; i++ )
            {

            }
    
            regValue = pio0->fstat;
            if (regValue &  (1u << (PIO_FSTAT_RXEMPTY_LSB + sm)))
            {
                goto pio0sm0fifo;
            }

            for (int i = 0 ; i < 1000; i++ )
            {
                
            }

            regValue = sio_hw->fifo_st;
            if (!(regValue & SIO_FIFO_ST_VLD_BITS))
            {
                continue;
            }
            switch (sio_hw->fifo_rd & 0x07)
            {
                case 0:
                    for (int i = 0 ; i < 100; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                    }
                    break;
                case 1:
                    for (int i = 0 ; i < 1000; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                    }
                    break;
                case 2:
                    for (int i = 0 ; i < 10000; i++ )
                    {
                        (void)sio_hw->fifo_rd;

                    }
                    break;
                case 3:
                    for (int i = 0 ; i < 100000; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                        
                    }
                    break;
                case 4:
                    for (int i = 0 ; i < 1000000; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                        
                    }
                    break;
                case 5:
                    for (int i = 0 ; i < 200; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                        
                    }
                    break;
                case 6:
                    for (int i = 0 ; i < 300; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                        
                    }
                    break;
                case 7:
                    for (int i = 0 ; i < 100; i++ )
                    {
                        (void)sio_hw->fifo_rd;
                        
                    }
                    break;
            }
            continue;

        pio0intr:
            pio0->intr = 0;
            continue;

        pio1intr:
            pio1->intr = 0;
            continue;

        pio0sm0fifo:
            pio_sm_get(pio0, 0);
            continue;


        }
    }
}

void SecondCorePollingLoopOuter()
{
    SecondCorePollingLoopCRef();
}


int main()
{
    Intialize();

    // RunTests();

    // Test second core.
    {
        // Allow time to connect USB serial monitor.
        for (int i = 0; i < 6; i++)
        {
            printf("Waiting...\n");
            sleep_ms(500);
        }

        printf("SecondCorePollingLoop() address: %08X\n", (uint)SecondCorePollingLoop);

        int value = SimpleFunc();

        printf("Still alive %d\n", value);

//    	multicore_launch_core1(SecondCorePollingLoopOuter);
    	//multicore_launch_core1(SecondCorePollingLoopCRef);



        while(1)
        {
            uint startCount = loopCount;
            sleep_ms(1000);
            uint endCount = loopCount;
            double cyclesPerLoop = (125000000.0) / (double)(endCount - startCount);

            printf ("Cycles per loop: %.2f %08X to %08X\n", cyclesPerLoop, startCount, endCount);
        }
    }

    return 0;
}
