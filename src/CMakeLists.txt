# midilib/src/CMakeLists.txt
cmake_minimum_required(VERSION 3.13)

file(GLOB MIDILIB_SOURCES "*.c")
file(GLOB MIDILIB_HEADERS "*.h")

# Remove problematic files
list(REMOVE_ITEM MIDILIB_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/m2rtttl.c"
)

add_library(midilib STATIC ${MIDILIB_SOURCES})

target_include_directories(midilib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Define endian macros for embedded (Pico is little-endian)
target_compile_definitions(midilib PRIVATE
    __BYTE_ORDER=__LITTLE_ENDIAN
    __LITTLE_ENDIAN=1234
    __BIG_ENDIAN=4321
)

target_compile_options(midilib PRIVATE -O2 -ansi -Wall -s)
