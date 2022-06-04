// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include <pico/stdlib.h>
#include <cstdlib>
#include <LedController.h>
#include "UnitDemo.h"

/*static*/ void UnitDemo::RunLedControllerLedDemo()
{
    for (int i = 0; ; i++)
    {
        LedController::instance.SetDriveActivity(i % 2 == 0);
        LedController::instance.SetLed(i % 50 < 20);

        if (i == 200)
        {
            LedController::instance.FlashErrorSequence(LedController::ErrorType::PrimarySdTooSmall);
        }

        sleep_ms(std::rand()% 100);
    }
}
