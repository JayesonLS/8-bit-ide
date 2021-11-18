@ Copyright (C) 2021 Titanium Studios Pty Ltd 
@ 
@ This program is free software : you can redistribute it and/or modify
@ it under the terms of the GNU General Public License as published by
@ the Free Software Foundation, either version 3 of the License, or
@ (at your option) any later version.
@ 
@ This program is distributed in the hope that it will be useful,
@ but WITHOUT ANY WARRANTY; without even the implied warranty of
@ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
@ GNU General Public License for more details.
@ 
@ You should have received a copy of the GNU General Public License
@ along with this program.If not, see < https://www.gnu.org/licenses/>.

#define _u(x) x

#include "XtBusDefs.h"

.syntax unified
.cpu cortex-m0plus
.thumb

.global loopCount

@ Timing:
@ 1. Responding interrupts from pio0 or pio1, and responding to fifo data from
@ pio0 are very time sensitive.
@ 2. Responding to data from the other CPU core is not time sentitive, however
@ we must process any incoming data very quickly to avoid being unable to respond
@ to the conditions in 1.

@ Locals during the main loop
@ r0 = scratch register
@ r1 = pointer to loopCount variable
@ r2 = write_control_register fifo rxempty test mask
@ r5 = pointer to write pio base
@ r6 = pointer to read pio base
@ r7 = pointer to sio base

.section .scratch_x.SecondCorePollingLoop, "ax"
.align 2
.global SecondCorePollingLoop
@.type SecondCorePollingLoop,%function
.thumb_func 
SecondCorePollingLoop:

0: @ Fucntion start.
    movs    r0, #0
    ldr     r1, =loopCount
    ldr     r2, =(1 << (PIO_FSTAT_RXEMPTY_LSB + WRITE_CONTROL_REGISTER_SM))
    ldr     r5, =WRITE_PIO_BASE 
    ldr     r6, =READ_PIO_BASE
    ldr     r7, =SIO_BASE

1: @ Loop start.
    @ Write to the fifo so the other CPU can count the loops.
    str     r0, [r7, SIO_FIFO_WR_OFFSET]

    @ Check pio0 intr
    ldr     r0, [r5, PIO_IRQ_OFFSET]
    lsls    r0, r0, #30
    bne.n   2f

    @ Check pio1 intr
    ldr     r0, [r6, PIO_IRQ_OFFSET]
    lsls    r0, r0, #31
    bne.n   3f

    @ Check pio0 sm0 fifo
    ldr     r0, [r5, PIO_FSTAT_OFFSET]
    tst     r0, r2
    beq.n    4f

    @ Check si0 fifo (data from other CPU core)
    ldr     r0, [r7, SIO_FIFO_ST_OFFSET]
    lsls    r0, r0, #31
    beq.n    1b

    @ There is data in the si0 fifo
    ldr     r0, [r7, SIO_FIFO_RD_OFFSET]
    mov     pc, r0                          @ The other CPU will give us the command handler address.

2:  @ A pio0 interrupt 0 and/or 1 flag is set
    @TODO: More to do here
    movs     r0, 0x03
    str     r0, [r5, PIO_IRQ_OFFSET]
    b.n     1b

3:  @ pio1 interrupt 0 flag is set
    @TODO: More to do here
    movs     r0, 0x01
    str     r0, [r6, PIO_IRQ_OFFSET]
    b.n     1b

4:  @ pio0 sm0 fifo has data
    @TODO: More to do here
    ldr     r0, [r5, PIO_RXF0_OFFSET]
    b.n     1b

.align 2
.global SecondCoreSetFlagsRegister
@.type SecondCoreSetFlagsRegister,%function
.thumb_func 
SecondCoreSetFlagsRegister:
    nop
    b.n     1b



.section .scratch_x.SimpleFunc, "ax"
.align 2
.global SimpleFunc
@.type SimpleFunc,%function
.thumb_func 
SimpleFunc:
    movs	r0, #1
    bx	lr
