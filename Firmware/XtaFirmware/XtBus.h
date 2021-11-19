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
};
