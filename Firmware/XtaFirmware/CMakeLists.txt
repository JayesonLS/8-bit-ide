if (TARGET tinyusb_device)
        add_executable(XtaFirmware
                XtaMain.cpp
                XtBus.cpp
                XtBusAsm.S
                )

        pico_generate_pio_header(XtaFirmware ${CMAKE_CURRENT_LIST_DIR}/XtBus.pio)
                
        # Pull in our pico_stdlib which aggregates commonly used features
        target_link_libraries(XtaFirmware CommonLib CommonTestsLib)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(XtaFirmware 1)
        pico_enable_stdio_uart(XtaFirmware 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(XtaFirmware)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building xta_firmware because TinyUSB submodule is not initialized in the SDK")
endif()
