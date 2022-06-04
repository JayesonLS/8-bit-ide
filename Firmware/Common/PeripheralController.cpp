// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include <pico/stdlib.h>
#include <cstdlib>
#include <IoConfig.h>
#include "PeripheralController.h"

/*static*/ PeripheralController PeripheralController::instance;

void PeripheralController::Initialize()
{
    // ~DRIVE_ACTIVE 
    gpio_init(IoConfig::INV_DRIVE_ACTIVE);
    gpio_set_dir(IoConfig::INV_DRIVE_ACTIVE, GPIO_OUT);
    gpio_put(IoConfig::INV_DRIVE_ACTIVE, true);

    // ~BOOT_OVERRIDE
    gpio_init(IoConfig::INV_BOOT_OVERRIDE);
    gpio_set_dir(IoConfig::INV_BOOT_OVERRIDE, GPIO_IN);
    gpio_pull_up(IoConfig::INV_BOOT_OVERRIDE);

    isInitialized = true;
}

// Set the state of the attached LED. 
void PeripheralController::SetLed(bool on)
{
    gpio_put(IoConfig::INV_DRIVE_ACTIVE, !on);
}

// Returns true if the button is down.
bool PeripheralController::GetBootOverrideButtonDown()
{
    return gpio_get(IoConfig::INV_BOOT_OVERRIDE) == false; // Button is pressed when when input pulled low. 
}

