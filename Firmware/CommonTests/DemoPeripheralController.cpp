// Copyright (C) 2021 Titanium Studios Pty Ltd 

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
