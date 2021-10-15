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

static inline void isaout_program_init(PIO pio, uint sm, uint offset, uint pin) 
{
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);

    pio_sm_config c = isaout_program_get_default_config(offset);
    sm_config_set_out_pins(&c, pin, 1);
    pio_sm_init(pio, sm, offset, &c);

    pio_sm_set_enabled(pio, sm, true);
}

int main()
{
    stdio_init_all();

    PIO pio = pio0;
    uint programOffset = pio_add_program(pio, &isaout_program);
    uint outSm = pio_claim_unused_sm(pio, true);
    isaout_program_init(pio, outSm, programOffset, PICO_DEFAULT_LED_PIN);

    for (int ledValue = 0; ; ledValue ^= 1)
    {
        printf("8bit_ide_drive heartbeat.\n");

        pio_sm_put_blocking(pio, outSm, ledValue);
        
        sleep_ms(1000);
    }

    return 0;
}
