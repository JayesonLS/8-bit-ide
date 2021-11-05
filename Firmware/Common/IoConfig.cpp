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
    sio_hw->gpio_oe_clr = INITIAL_INPUTS;
    sio_hw->gpio_clr = INITIAL_INPUTS | INITIAL_OUTPUTS_LOW;
    sio_hw->gpio_set = INITIAL_OUTPUTS_HIGH;
    sio_hw->gpio_oe_set = INITIAL_OUTPUTS;

    // TODO: Do we need to set the IO functions here with gpio_set_function()?
}