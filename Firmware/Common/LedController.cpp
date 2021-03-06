// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include <pico/stdlib.h>
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
