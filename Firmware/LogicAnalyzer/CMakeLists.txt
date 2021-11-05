if (TARGET tinyusb_device)
        add_executable(LogicAnalyzer
                LaMain.cpp
                LogicAnalyzer.cpp
                )

        pico_generate_pio_header(LogicAnalyzer ${CMAKE_CURRENT_LIST_DIR}/LogicAnalyzer.pio)
                
        # Pull in needed libraries.
        target_link_libraries(LogicAnalyzer CommonLib)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(LogicAnalyzer 1)
        pico_enable_stdio_uart(LogicAnalyzer 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(LogicAnalyzer)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building LogicAnalyzer because TinyUSB submodule is not initialized in the SDK")
endif()
