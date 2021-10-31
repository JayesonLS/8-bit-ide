cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(8bit_ide_drive C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

if (TARGET tinyusb_device)
        add_executable(8bit_ide_drive
                8bit_ide_drive.cpp
                )

        pico_generate_pio_header(8bit_ide_drive ${CMAKE_CURRENT_LIST_DIR}/isaout.pio)
        pico_generate_pio_header(8bit_ide_drive ${CMAKE_CURRENT_LIST_DIR}/data_buffer.pio)
                
        # Pull in our pico_stdlib which aggregates commonly used features
        target_link_libraries(8bit_ide_drive pico_stdlib hardware_pio hardware_dma)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(8bit_ide_drive 1)
        pico_enable_stdio_uart(8bit_ide_drive 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(8bit_ide_drive)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building 8bit_ide_drive because TinyUSB submodule is not initialized in the SDK")
endif()
