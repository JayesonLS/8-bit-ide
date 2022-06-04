// Copyright (C) 2021 Titanium Studios Pty Ltd 

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

private:
    bool isInitialized = false;
};
