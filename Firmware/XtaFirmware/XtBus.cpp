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

#include "XtBus.h"
#include <hardware/dma.h>
#include <hardware/structs/bus_ctrl.h>
#include "XtBus.pio.h"

/*static*/ XtBus XtBus::instance;

XtBus::XtBus()
{
    if ((void *)writePio != (void *)WRITE_PIO_BASE ||
        (void *)readPio != (void *)READ_PIO_BASE)
    {
        panic("Inconsistent PIO assignments.");
    }
}

void XtBus::Initialize()
{
    // Set up write_control_register program.
    {
        writeControlRegisterProgramOffset = pio_add_program(writePio, &write_control_register_program);
        pio_sm_config c = write_control_register_program_get_default_config(writeControlRegisterProgramOffset);
        sm_config_set_in_pins(&c, FIRST_WRITE_DECODE_PIN);
        sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
        sm_config_set_jmp_pin(&c, IoConfig::INV_IOW);
        uint initialPc = writeControlRegisterProgramOffset + write_control_register_wrap_target; // Start at the wrap target.
        pio_sm_init(writePio, WRITE_CONTROL_REGISTER_SM, initialPc, &c);

        // Force a -1 into Y so initial wait-for-write-end does not push a value into the fifo.
        pio_sm_exec(writePio, WRITE_CONTROL_REGISTER_SM, pio_encode_mov_not(pio_y, pio_null));
    }

    // Start state machines.
    pio_sm_set_enabled(writePio, WRITE_CONTROL_REGISTER_SM, true);
}