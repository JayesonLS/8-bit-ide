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
#include <stdio.h>
#include <PeripheralController.h>
#include <LedController.h>
#include "UnitDemo.h"

/*static*/ void UnitDemo::RunPerphieralControllerButtonDemo()
{
    bool lastButtonDown = false;

    printf("Press and release button. Messages should print and the LED's should toggle.\n");

    while (true)
    {
        bool buttonDown = PeripheralController::instance.GetBootOverrideButtonDown();
        if (buttonDown != lastButtonDown)
        {
            printf("Button is %s\n", buttonDown ? "down" : "up");
            lastButtonDown = buttonDown;

            LedController::instance.SetLed(buttonDown);
        }

        sleep_ms(20);
    }
}
