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
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "isaout.pio.h"

int main()
{
    stdio_init_all();

    PIO pio = pio0;
    uint programOffset = pio_add_program(pio, &isaout_program);
    uint outSm = pio_claim_unused_sm(pio, true);
    isaout_program_init(pio, outSm, programOffset, 0, 8, 2, 10);

    for (int ledValue = 0; ; ledValue++)
    {
        //printf("8bit_ide_drive heartbeat.\n");

        pio_sm_put_blocking(pio, outSm, ledValue); 
        
//        sleep_ms(100);
    }

    return 0;
}
