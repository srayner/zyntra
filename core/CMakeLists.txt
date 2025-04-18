cmake_minimum_required(VERSION 3.10)
project(zyntra_core)

set(CMAKE_CXX_STANDARD 17)

# Core source files (excluding main.cpp)
set(CORE_SOURCES
    src/checksum.cpp
    src/command_builder.cpp
)

# Main executable
add_executable(zyntra_core
    src/main.cpp
    ${CORE_SOURCES}
)

# Test executable
add_executable(zyntra_tests
    tests/test_checksum.cpp
    tests/test_command_builder.cpp
    ${CORE_SOURCES}
)

# Link extra libraries if needed (e.g., pthread for Catch2 if using threads)
# target_link_libraries(zyntra_tests pthread)

