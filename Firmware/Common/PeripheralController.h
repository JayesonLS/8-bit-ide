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

// Controller for external peripherals. Currently just controls LED and
// button directly connected to GPIOs. However things are set up for 
// attaching an i2c bus expander to those pins so we can have more things
// attached. Stepper motor control for example.
class PeripheralController
{
public:
    static PeripheralController instance;

    void Initialize();
    bool IsIntialized() { return isInitialized; }

    // Set the state of the attached LED. 
    void SetLed(bool on);

    // Returns true if the button is down.
    bool GetBootOverrideButtonDown();

#ifndef DISABLE_TESTS
    static void RunButtonDemo();
#endif

private:
    bool isInitialized = false;
};
