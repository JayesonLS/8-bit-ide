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

#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/pio.h>
#include "logic_analyzer.h"
#include "isaout.pio.h"

const uint CAPTURE_START_PIN = 0;
const uint CAPTURE_PIN_COUNT = 29;

void InitIsaOut(PIO pio, uint &isaOutSm)
{
    uint programOffset = pio_add_program(pio, &isaout_program);
    isaOutSm = pio_claim_unused_sm(pio, true);
    isaout_program_init(pio, isaOutSm, programOffset, 0, 8, 2, 10);
}

void IsaOutOutputValue(PIO pio, uint isaOutSm, uint value)
{
    pio_sm_put_blocking(pio, isaOutSm, value); 
}

int main()
{
    stdio_init_all();

    PIO isaOutPio = pio0;
    uint isaOutSm = 0xAA55;
    InitIsaOut(isaOutPio, isaOutSm);

    for (int ledValue = 0; ; ledValue++)
    {
        //printf("8bit_ide_drive heartbeat.\n");

        IsaOutOutputValue(isaOutPio, isaOutSm, ledValue);
        
        sleep_ms(100);
    }

    return 0;
}
