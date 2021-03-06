// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include "XtBus.h"
#include <hardware/dma.h>
#include <hardware/structs/bus_ctrl.h>
#include "XtBus.pio.h"

/*static*/ XtBus XtBus::instance;

XtBus::XtBus()
{
    if ((void *)writePio != (void *)WRITE_PIO_BASE ||
        (void *)readPio != (void *)READ_PIO_BASE)
    {
        panic("Inconsistent PIO assignments.");
    }
}

void XtBus::Initialize()
{
    static_assert(FIRST_BUS_PIN <= IoConfig::D0 && IoConfig::DATA_DIR > IoConfig::D7 && IoConfig::D7 > IoConfig::D0);

    // Set up write_control_register program.
    {
        writeControlRegisterProgramOffset = pio_add_program(writePio, &write_control_register_program);
        pio_sm_config c = write_control_register_program_get_default_config(writeControlRegisterProgramOffset);
        sm_config_set_in_pins(&c, FIRST_WRITE_DECODE_PIN);
        sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
        sm_config_set_jmp_pin(&c, IoConfig::INV_IOW);
        uint initialPc = writeControlRegisterProgramOffset + write_control_register_wrap_target; // Start at the wrap target.
        pio_sm_init(writePio, WRITE_CONTROL_REGISTER_SM, initialPc, &c);

        // Load 0xFFFFFFFF into Y so initial wait-for-write-end does not push a value into the fifo.
        pio_sm_exec(writePio, WRITE_CONTROL_REGISTER_SM, pio_encode_mov_not(pio_y, pio_null));
    }

    // Set up read_control_register program.
    {
        readControlRegisterProgramOffset = pio_add_program(readPio, &read_control_register_program);
        pio_sm_config c = read_control_register_program_get_default_config(readControlRegisterProgramOffset);
        sm_config_set_in_pins(&c, FIRST_READ_DECODE_PIN);
        sm_config_set_out_pins(&c, IoConfig::D0, 8);
        sm_config_set_sideset_pins(&c, IoConfig::DATA_DIR);
        sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);
        sm_config_set_jmp_pin(&c, IoConfig::INV_IOR); 
        uint initialPc = readControlRegisterProgramOffset + read_control_register_wrap_target + 1; // Start 1 instruction past the wrap target.
        pio_sm_init(readPio, READ_CONTROL_REGISTER_SM, initialPc, &c);

        // Load 0 into X (set the initial register values).
        pio_sm_exec(readPio, READ_CONTROL_REGISTER_SM, pio_encode_mov(pio_x, pio_null));
    }

    // Set up set_pindirs program.
    {
        setupPindirsProgramOffset = pio_add_program(readPio, &set_pindirs_program);
        pio_sm_config c = set_pindirs_program_get_default_config(setupPindirsProgramOffset);
        sm_config_set_in_pins(&c, FIRST_READ_DECODE_PIN);
        sm_config_set_out_pins(&c, IoConfig::D0, 8);
        sm_config_set_sideset_pins(&c, IoConfig::DATA_DIR);
        sm_config_set_jmp_pin(&c, IoConfig::INV_IOR);
        uint initialPc = setupPindirsProgramOffset; // Start of the program is fine.
        pio_sm_init(readPio, SET_PINDIRS_SM, initialPc, &c);

        // Load 0x000000FF into X.
        pio_sm_exec(readPio, SET_PINDIRS_SM, pio_encode_mov_not(pio_osr, pio_null)); // 0xFFFFFFFF into OSR
        pio_sm_exec(readPio, SET_PINDIRS_SM, pio_encode_out(pio_x, 8)); // Shift 8 bits from OSR into X. Rest will be 0's.
    }

    // Init DATA_DIR and set as an output.
#ifdef NEW_BOARD
    pio_sm_set_pins_with_mask(readPio, SET_PINDIRS_SM, 0, (1 << IoConfig::DATA_DIR));
#else
    pio_sm_set_pins_with_mask(readPio, SET_PINDIRS_SM, (1 << IoConfig::DATA_DIR), (1 << IoConfig::DATA_DIR));
#endif
    pio_sm_set_pindirs_with_mask(readPio, SET_PINDIRS_SM, (1 << IoConfig::DATA_DIR), (1 << IoConfig::DATA_DIR)); 

    // Configure needed pins to be driven by the read PIO.
    for (uint pinIndex = 0; pinIndex < 32; pinIndex++)
    {
        if (IoConfig::READ_DRIVE_PINS & (1 << pinIndex))
        {
            pio_gpio_init(readPio, pinIndex);
        }
    }

    // We need DATA_DIR to have fast transition speeds to be sure it completes transition within a single clock 
    // cycle. With this setting, the transiton completes in about 70% of a clock cycle.
    gpio_set_drive_strength(IoConfig::DATA_DIR, GPIO_DRIVE_STRENGTH_12MA);    
	// We also want it to bypass the 2-flip-flip synchonizer to avoid the extra 2 cycle input latency.
    // Don't do this without also maxing the drive strength. 
    readPio->input_sync_bypass |= (1 << IoConfig::DATA_DIR);

    // TODO: Move this to IoConfig as it will be common on  DBA8.
    {
        // Invert the input state of INV_IRQ and INV_DRQ.  
        gpio_set_inover(IoConfig::INV_DRQ, GPIO_OVERRIDE_INVERT);
        gpio_set_inover(IoConfig::INV_IRQ, GPIO_OVERRIDE_INVERT);

        // TODO: Should also flip the drive state to somewhat avoid confusion.
        // Must be done carefully to avoid accidentally driving the output.
    }

    // Start state machines.
    pio_sm_set_enabled(readPio, SET_PINDIRS_SM, true);
    pio_sm_set_enabled(readPio, READ_CONTROL_REGISTER_SM, true);
    pio_sm_set_enabled(writePio, WRITE_CONTROL_REGISTER_SM, true);
}