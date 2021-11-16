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


#define __scratch_x_func(func_name) __scratch_x(__STRING(func_name)) func_name

extern "C"
{
    volatile uint __scratch_x_func(loopCount);
    extern void SecondCorePollingLoop();

    void __scratch_x_func(SecondCorePollingLoopCRef)()
    {
        uint count = 0;

        // Just a mock up of what the tight polling loop needs to do.

        while(1)
        {
    //        if (pio0->intr)
    //        {
    //            pio0->intr = 0;
    //        }
    //
    //        if (pio1->intr)
    //        {
    //            pio1->intr = 0;
    //        }
    //
    //        if (!pio_sm_is_rx_fifo_empty(pio0, 0))
    //        {
    //            pio_sm_get(pio0, 0);
    //        }
    //
    //        if (sio_hw->fifo_st & SIO_FIFO_ST_VLD_BITS)
    //        {
    //            (void) sio_hw->fifo_rd;
    //        }

            count++;
            loopCount = count;
        }
    }
}

void SecondCorePollingLoopOuter()
{
    SecondCorePollingLoop();
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

    	multicore_launch_core1(SecondCorePollingLoopOuter);
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
