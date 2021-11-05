add_library(CommonLib INTERFACE)
target_sources(CommonLib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/DeviceId.cpp
	${CMAKE_CURRENT_LIST_DIR}/sha1/sha1.c
    ${CMAKE_CURRENT_LIST_DIR}/fatfs/source/ff.c
    ${CMAKE_CURRENT_LIST_DIR}/fatfs/source/ffsystem.c
    ${CMAKE_CURRENT_LIST_DIR}/fatfs/source/ffunicode.c
    ${CMAKE_CURRENT_LIST_DIR}/tf_card/tf_card.c
)

target_include_directories(CommonLib INTERFACE
    .
    fatfs/source
)

target_link_libraries(CommonLib INTERFACE
    pico_stdlib
    hardware_adc
    hardware_clocks
    hardware_spi
    hardware_pio
    hardware_dma
)