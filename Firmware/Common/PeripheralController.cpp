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

