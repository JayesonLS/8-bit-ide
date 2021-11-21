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

#pragma once

// Centralized configuration for RP2040 GPIO's. 
class IoConfig
{
public:
    // Pin assignments.
    static const uint SPI_RX = 0;
    static const uint SD0_CS = 1;
    static const uint SPI_SCK = 2;
    static const uint SPI_TX = 3;
    static const uint SD1_CS = 4;
    static const uint D0 = 5;
    static const uint D1 = 6;
    static const uint D2 = 7;
    static const uint D3 = 8;
    static const uint D4 = 9;
    static const uint D5 = 10;
    static const uint D6 = 11;
    static const uint D7 = 12;
    static const uint INV_DACK = 13;
    static const uint INV_IOW = 14;
    static const uint A0 = 15;
    static const uint A1 = 16;
    static const uint INV_CS = 17;
    static const uint AEN = 18;
    static const uint INV_IOR = 19;
    static const uint INV_DRQ = 20;
    static const uint INV_IRQ = 21;
    static const uint DATA_DIR = 22;

    // Pico specific GPIO assignments.
    static const uint PICO_PS_MODE = 23; // We always want 0 for PFM = higher noise and efficiency.
    static const uint PICO_VBUS_SENSE = 24; // High when USB power present.
    static const uint PICO_LED = 25; // The built in LED.

    // These next two have been mapped to i2c pins so we have the option
    // later of switching to a PCF8574 bus expander and being able to
    // detect it.  
    static const uint INV_BOOT_OVERRIDE = 26; // Also ADC0.
    static const uint INV_DRIVE_ACTIVE = 27;  // Also ADC1.
    static const uint INV_RESET = 28;         // Also ADC2.
    
    static const uint PICO_VSYS_SENSE = 29;   // Also ADC3. Intended to be read with the ADC.

    // Pin groupings.
    static const uint INITIAL_INPUTS =
        (1 << SPI_RX) | (1 << SD0_CS) | (1 << SPI_SCK) | (1 << SPI_TX) | (1 << SD1_CS) | 
        (1 << D0) | (1 << D1) | (1 << D2) | (1 << D3) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7) |
        (1 << INV_DACK) | (1 << INV_IOR) | (1 << INV_IOW) | (1 << INV_CS) | (1 << AEN) || (1 << A0) | (1 << A1); 
#ifdef NEW_BOARD
    static const uint INITIAL_OUTPUTS_LOW = (1 << DATA_DIR);
    static const uint INITIAL_OUTPUTS_HIGH = (1 << INV_DRQ) | (1 << INV_IRQ) | (1 << PICO_LED);
#else
    static const uint INITIAL_OUTPUTS_LOW = 0;
    static const uint INITIAL_OUTPUTS_HIGH = (1 << INV_DRQ) | (1 << INV_IRQ) | (1 << PICO_LED) | (1 << DATA_DIR);
#endif
    static const uint EXTERNAL_PULL_PINS = INITIAL_OUTPUTS_LOW | INITIAL_OUTPUTS_HIGH;
    static const uint INITIAL_OUTPUTS = INITIAL_OUTPUTS_LOW | INITIAL_OUTPUTS_HIGH;
    static const uint INITIAL_INPUTS_AND_OUTPUTS = INITIAL_INPUTS | INITIAL_OUTPUTS;

    static const uint READ_DRIVE_PINS =
        (1 << D0) | (1 << D1) | (1 << D2) | (1 << D3) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7) |
        (1 << DATA_DIR);

    // Method that should be called very early in startup process
    // to configure initial IO pin state. 
    static void PreInitialzieIo();

    static void FinishInitializeIo();
};
