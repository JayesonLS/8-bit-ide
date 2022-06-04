// Copyright (C) 2021 Titanium Studios Pty Ltd 

#pragma once

#include <pico/stdlib.h>
#include <hardware/pio.h>
#include "XtBusDefs.h"
#include <IoConfig.h>

class XtBus
{
public:
    static XtBus instance;

    XtBus();

    void Initialize();

private:
    static const uint FIRST_BUS_PIN = IoConfig::D0;
    static const uint FIRST_WRITE_DECODE_PIN = FIRST_BUS_PIN;
    static const uint FIRST_READ_DECODE_PIN = IoConfig::A0;

    // These assigments must match the assignments in XtBusDefs.h 
    const PIO writePio = pio0;
    const PIO readPio = pio1;

    uint writeControlRegisterProgramOffset = 0xBADA;
    uint readControlRegisterProgramOffset = 0xBADA;
    uint setupPindirsProgramOffset = 0xBADA;
};
