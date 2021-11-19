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
    // We don't call gpio_init() for two reasons. First
    // is that it will be a little slower as it only does
    // one pin at a time. Second is that it will switch
    // everything to inputs first while we want some to 
    // be outputs. If we are doing some kind of reset and
    // the registers have not been set to default values,
    // then better to assume some pins might already be in
    // the state that we want.

    // The order here is chosen on purpose.
    // First, disable any outputs that should not be inputs,
    // then clear/set in/out values as needed, then enable
    // outputs.
    sio_hw->gpio_oe_clr = INITIAL_INPUTS;
    sio_hw->gpio_clr = INITIAL_INPUTS | INITIAL_OUTPUTS_LOW;
    sio_hw->gpio_set = INITIAL_OUTPUTS_HIGH;
    sio_hw->gpio_oe_set = INITIAL_OUTPUTS;

    // To start, configure any pins we are using as SIO's.
    // gpio_set_function enables inputs/outputs to function 
    // It also clears all of the GPIOx_CONTROL register
    // (signal inversions, etc.) except for setting the
    // function to SIO. 
    for (uint pinIndex = 0; pinIndex < 32; pinIndex++)
    {
        if (INITIAL_INPUTS_AND_OUTPUTS & (1 << pinIndex))
        {
            gpio_set_function(pinIndex, GPIO_FUNC_SIO);
        }

        // Disable the pullups resistors for pins with external pullups.
        // No need to load the pin any further.
        if (EXTERNAL_PULL_PINS & (1 << pinIndex))
        {
            gpio_disable_pulls(pinIndex);            
        }
    }
}