add_library(Common INTERFACE)
target_sources(Common INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/DeviceId.cpp
	${CMAKE_CURRENT_LIST_DIR}/sha1/sha1.c
)

target_include_directories(Common INTERFACE
    .
)

target_link_libraries(Common INTERFACE
        hardware_adc
        pico_stdlib
)