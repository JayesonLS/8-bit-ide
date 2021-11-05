if (TARGET tinyusb_device)
        add_executable(Dba8Firmware
                Dba8Main.cpp
                )

        pico_generate_pio_header(Dba8Firmware ${CMAKE_CURRENT_LIST_DIR}/DataBuffer.pio)
        pico_generate_pio_header(Dba8Firmware ${CMAKE_CURRENT_LIST_DIR}/ControlRegisters.pio)
                
        # Pull in our pico_stdlib which aggregates commonly used features
        target_link_libraries(Dba8Firmware CommonLib)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(Dba8Firmware 1)
        pico_enable_stdio_uart(Dba8Firmware 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(Dba8Firmware)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building xta_firmware because TinyUSB submodule is not initialized in the SDK")
endif()
