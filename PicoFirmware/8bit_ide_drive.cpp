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
#include "isaout.pio.h"

bool _doCall = false;

static inline void isaout_program_init(PIO pio, uint sm, uint offset, uint addr_data_base_pin, uint iow_base_pin) 
{
    const uint NUM_ADDR_DATA_PINS = 10;

    pio_sm_set_consecutive_pindirs(pio, sm, addr_data_base_pin, NUM_ADDR_DATA_PINS, true);
    pio_sm_set_consecutive_pindirs(pio, sm, iow_base_pin, 1, true);
    for (uint i = addr_data_base_pin; i < addr_data_base_pin + NUM_ADDR_DATA_PINS; i++)
    {
        pio_gpio_init(pio, i);
    }
    pio_gpio_init(pio, iow_base_pin);

    pio_sm_config c = isaout_program_get_default_config(offset);
    sm_config_set_out_pins(&c, addr_data_base_pin, NUM_ADDR_DATA_PINS);
    sm_config_set_sideset_pins(&c, iow_base_pin);
    sm_config_set_out_shift(&c, true, true, 10);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

int main()
{
    stdio_init_all(); 

    {
        // LED on so we know the program has started. 
        gpio_init(PICO_DEFAULT_LED_PIN);
        gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
        gpio_put(PICO_DEFAULT_LED_PIN, true);
    }

    PIO pio = pio0;

    const uint OUT_ADDR_DATA_BASE_PIN = 0;
    const uint OUT_IOW_PIN = 10;
    uint outSm = pio_claim_unused_sm(pio, true);;

    if (_doCall)
    {   
        uint out_prog_offs = pio_add_program(pio, &isaout_program);
        isaout_program_init(pio, outSm, out_prog_offs, OUT_ADDR_DATA_BASE_PIN, OUT_IOW_PIN);
    }
    int currentAddr = 0;

    while (true)
    {
        int c = getchar_timeout_us(0);
        if (c != PICO_ERROR_TIMEOUT)
        {
            // We have a character.
            putchar(c); // Echo back to serial.

            // Perform a blocking write to isaout state machine.
            uint dataOut = (c & 0xFF) | (currentAddr << 8);

            if (_doCall)
            {
                // Simply linking in this method is causing the USB serial device to fail.
                // Windows device manager says "Device Descriptor Request Failed".
                // Unsure of why at the moment. Adding USB serial to the hello_pio sample
                // works so next step will be to  restart with something closer to that.  
                pio_sm_put_blocking(pio, outSm, dataOut);

                currentAddr = (currentAddr + 1) & 0x03;
            }
        }
    }
    return 0;
}
