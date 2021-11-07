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
