// Copyright (C) 2021 Titanium Studios Pty Ltd 

#pragma once

class UnitDemo
{
public:
    // These do not return. The module being demoed must already
    // be initalized. Some modules require other modules to be 
    // initialized.
    static void RunPerphieralControllerButtonDemo();
    static void RunLedControllerLedDemo();
};
