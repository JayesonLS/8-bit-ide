add_library(CommonTestsLib INTERFACE)
target_sources(CommonTestsLib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/UnitTest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TestDeviceId.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TestLbaTranslation.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DemoPeripheralController.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DemoLedController.cpp
)

target_include_directories(CommonTestsLib INTERFACE
    .
)

target_link_libraries(CommonTestsLib INTERFACE
    pico_stdlib
    CommonLib
)