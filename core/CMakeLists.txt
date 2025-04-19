cmake_minimum_required(VERSION 3.10)
project(zyntra_core)

set(CMAKE_CXX_STANDARD 17)

# Include folders
include_directories(include)

# Find all source files
file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")

# Find test files
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Remove main.cpp from CORE_SOURCES
list(REMOVE_ITEM CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Build main executable
add_executable(zyntra_core src/main.cpp ${CORE_SOURCES})

# Build tests executable
add_executable(zyntra_tests ${TEST_SOURCES} ${CORE_SOURCES})
