cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(logic_analyzer C CXX ASM)
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
        add_executable(LogicAnalyzer
                la_main.cpp
                logic_analyzer.cpp
                )

        pico_generate_pio_header(LogicAnalyzer ${CMAKE_CURRENT_LIST_DIR}/logic_analyzer.pio)
                
        # Pull in needed libraries.
        target_link_libraries(LogicAnalyzer common_lib pico_stdlib hardware_pio hardware_dma hardware_adc)
    
        # enable usb output, disable uart output
        pico_enable_stdio_usb(LogicAnalyzer 1)
        pico_enable_stdio_uart(LogicAnalyzer 0)
    
        # create map/bin/hex/uf2 file etc.
        pico_add_extra_outputs(LogicAnalyzer)
elseif(PICO_ON_DEVICE)
        message(WARNING "not building LogicAnalyzer because TinyUSB submodule is not initialized in the SDK")
endif()
