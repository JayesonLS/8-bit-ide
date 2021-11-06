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
#include <IoConfig.h>
#include "LedController.h"
#include "PeripheralController.h"

/*static*/ LedController LedController::instance;

void LedController::Initialize()
{
    // Led on board the Pico.
    gpio_init(IoConfig::PICO_LED);
    gpio_set_dir(IoConfig::PICO_LED, GPIO_OUT);

    if (!PeripheralController::instance.IsIntialized())
    {
        panic("PeripheralController should be initialized first.");
    }

    Update();
}

void LedController::SetDriveActivity(bool active)
{
    driveActiveState = active;
    Update();
}

void LedController::SetLed(bool on)
{
    setState = on;
    Update();
}

void LedController::FlashErrorSequence(ErrorType errorTypeIn)
{
    assert(errorTypeIn >= ErrorType::None && errorTypeIn < ErrorType::Num && errorTypeIn != ErrorType::Invalid);

    errorType = errorTypeIn;
    Update();
}

void LedController::Update()
{
    bool nextLedState = driveActiveState;

    nextLedState |= setState;

    if (errorType == ErrorType::None)
    {
        flashState = FlashState::NotFlashing;
    }
    else
    {
        uint32_t currentTime = time_us_32();

        switch  (flashState)
        {
            case FlashState::NotFlashing:
                flashState = FlashState::FlashOn;
                flashCount = 0;
                lastStartTime = currentTime;
                break;
            case FlashState::FlashOn:
                if (currentTime - lastStartTime >= ERROR_FLASH_ON_MS * 1000)
                {
                    flashState = FlashState::FlashOff;
                    lastStartTime = currentTime;
                }
                break;
            case FlashState::FlashOff:
                if (currentTime - lastStartTime >= ERROR_FLASH_OFF_MS * 1000)
                {
                    flashCount++;

                    if (flashCount >= (size_t)errorType) // Enum value equals number of flashes. 
                    {
                        flashState = FlashState::DelayBetweenFlashes;
                    }
                    else
                    {
                        flashState = FlashState::FlashOn;
                    }
                    lastStartTime = currentTime;
                }
                break;
            case FlashState::DelayBetweenFlashes:
                if (currentTime - lastStartTime >= ERROR_FLASH_BETWEEN_MS * 1000)
                {
                    flashState = FlashState::FlashOn;
                    lastStartTime = currentTime;
                    flashCount = 0;
                }
                break;
            default:
                panic("Unhandled switch.");
                break;
        }

        nextLedState = flashState == FlashState::FlashOn;
    }

    if (nextLedState != lastLedState)
    {
        // Update both the Pico built in LED and the one controlled by
        // the PeripheralController/
        gpio_put(IoConfig::PICO_LED, nextLedState);
        PeripheralController::instance.SetLed(nextLedState);
        lastLedState = nextLedState;
    }
}

#ifndef DISABLE_TESTS
/*static*/ void LedController::RunLedDemo()
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
#endif