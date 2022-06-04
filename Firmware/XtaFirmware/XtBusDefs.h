// Copyright (C) 2021 Titanium Studios Pty Ltd 

#ifndef XT_BUS_DEFS_H
#define XT_BUS_DEFS_H

#include "hardware/regs/addressmap.h"
#include "hardware/regs/sio.h"
#include "hardware/regs/pio.h"

#define WRITE_PIO_BASE PIO0_BASE
#define READ_PIO_BASE PIO1_BASE

#define WRITE_CONTROL_REGISTER_SM 0

#define READ_CONTROL_REGISTER_SM 0
#define SET_PINDIRS_SM 1

#endif // XT_BUS_DEFS_H
