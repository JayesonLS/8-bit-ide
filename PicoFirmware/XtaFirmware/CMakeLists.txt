cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(XtaFirmware C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Include common library
add_subdirectory(../Common build)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

if (TARGET tinyusb_device)
        add_executable(XtaFirmware
                XtaMain.cpp
                )

        pico_generate_pio_header(XtaFirmware ${CMAKE_CURRENT_LIST_DIR}/isaout.pio)
        pico_generate_pio_header(XtaFirmware ${CMAKE_CURRENT_LIST_DIR}/DataBuffer.pio)
        pico_generate_pio_header(XtaFirmware ${CMAKE_CURRENT_LIST_DIR}/ControlRegisters.pio)
                
        # Pull in our pico_stdlib which aggregates commonly used features
        target_link_libraries(XtaFirmware CommonLib pico_stdlib hardware_pio hardware_dma)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(XtaFirmware 1)
        pico_enable_stdio_uart(XtaFirmware 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(XtaFirmware)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building xta_firmware because TinyUSB submodule is not initialized in the SDK")
endif()
