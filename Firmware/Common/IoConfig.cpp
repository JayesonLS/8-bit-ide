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

#include <pico/stdlib.h>
#include "IoConfig.h"

/*static*/ void IoConfig::PreInitialzieIo()
{
    // The order here is chosen on purpose.
    // First, disable any outputs that should not be inputs,
    // then clear/set in/out values as needed, then enable
    // outputs.
    sio_hw->gpio_oe_clr = INITIAL_INPUTS;
    sio_hw->gpio_clr = INITIAL_INPUTS | INITIAL_OUTPUTS_LOW;
    sio_hw->gpio_set = INITIAL_OUTPUTS_HIGH;
    sio_hw->gpio_oe_set = INITIAL_OUTPUTS;

    // To start, configure any pins we are using as SIO's.
    for (uint pinIndex = 0, mask = INITIAL_INPUTS_AND_OUTPUTS; pinIndex < 32; pinIndex++, mask >>= 1)
    {
        if (mask & 0x01)
        {
            gpio_set_function(pinIndex, GPIO_FUNC_SIO);
        }
    }
    gpio_set_function()

     GPIO_FUNC_XIP = 0,
    GPIO_FUNC_SPI = 1,
    GPIO_FUNC_UART = 2,
    GPIO_FUNC_I2C = 3,
    GPIO_FUNC_PWM = 4,
    GPIO_FUNC_SIO = 5,
    GPIO_FUNC_PIO0 = 6,
    GPIO_FUNC_PIO1 = 7,
    GPIO_FUNC_GPCK = 8,
    GPIO_FUNC_USB = 9,
    GPIO_FUNC_NULL = 0x1f,   
}