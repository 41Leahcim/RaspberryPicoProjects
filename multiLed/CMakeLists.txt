# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/michael/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(multiLed C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(multiLed multiLed.c )

pico_set_program_name(multiLed "multiLed")
pico_set_program_version(multiLed "0.1")

pico_enable_stdio_uart(multiLed 1)
pico_enable_stdio_usb(multiLed 0)

# Add the standard library to the build
target_link_libraries(multiLed pico_stdlib)

# Add any user requested libraries
target_link_libraries(multiLed
        hardware_pio
        )

pico_add_extra_outputs(multiLed)

