# Copyright (C) 2021 Titanium Studios Pty Ltd 
# 
# This program is free software : you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.If not, see < https://www.gnu.org/licenses/>.

#include "hardware/regs/addressmap.h"
#include "hardware/regs/pio.h"

.syntax unified
.cpu cortex-m0plus
.thumb

.global loopCount

.section .scratch_x, "ax"

.align 2
#.section .time_critical.SecondCorePollingLoop
.global SecondCorePollingLoop
#.type SecondCorePollingLoop,%function
.thumb_func
SecondCorePollingLoop:
    movs    r3, #0
    ldr     r2, =loopCount
1:
    adds	r3, #1
    str     r3, [r2, #0]
    b.n     1b
