cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(sslcert C CXX ASM)

project(pico_wifi_example)

# Initialize the SDK
pico_sdk_init()

add_executable(pico_wifi_example
    wifi_code.c
)

target_include_directories(pico_wifi_example PRIVATE
    ${PICO_SDK_PATH}/lib/lwip/src/include
    ${CMAKE_CURRENT_LIST_DIR}
)


# Link with the necessary libraries
target_link_libraries(pico_wifi_example pico_stdlib pico_cyw43_arch_lwip_threadsafe_background)

# Enable USB output
pico_enable_stdio_usb(pico_wifi_example 1)
pico_enable_stdio_uart(pico_wifi_example 0)

# Create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(pico_wifi_example)
