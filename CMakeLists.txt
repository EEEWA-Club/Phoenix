# Specify the system name and version
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.26)

# Specify cross-compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Project settings
project(Phoenix C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Compiler flags
add_compile_options(
    -mcpu=cortex-m4
    -mthumb
    -mthumb-interwork
    -ffunction-sections
    -fdata-sections
    -fno-common
    -fmessage-length=0
)

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)

# Optimization settings
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimisation for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimisation for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimisation for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimisation, debug info included")
    add_compile_options(-Og -g)
endif ()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/STM32F4/Core/Inc
    ${CMAKE_SOURCE_DIR}/STM32F4/Drivers/STM32F4xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/STM32F4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    ${CMAKE_SOURCE_DIR}/STM32F4/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ${CMAKE_SOURCE_DIR}/STM32F4/Drivers/CMSIS/Include
)

# Definitions
add_definitions(-DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE)

# Source files
file(GLOB_RECURSE SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/STM32F4/Core/*.*
    ${CMAKE_SOURCE_DIR}/STM32F4/Drivers/*.*
)

# Linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F4/STM32F401RETX_FLASH.ld)

# Linker options
add_link_options(
    -Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map
    -mcpu=cortex-m4
    -mthumb
    -mthumb-interwork
    -T ${LINKER_SCRIPT}
)

# Create the executable
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

# Output files
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

# Create hex and binary files
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMENT "Building ${HEX_FILE}\nBuilding ${BIN_FILE}"
)
