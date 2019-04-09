# ======================================================================
# CMake mandatory command
# ======================================================================
cmake_minimum_required(VERSION 3.12)

# ======================================================================
# Project related configuration
# ======================================================================
project("Arkanoid")

# ======================================================================
# CMake command
# ======================================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(COMPILER_FLAGS "-march=native")
set(COMPILER_WARRNINGS "-Wall -Werror -Wextra")

set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${COMPILER_WARRNINGS}")

# ======================================================================
# External libraries configuration
# ======================================================================

# ======================================================================
# Test configuration
# ======================================================================

# ======================================================================
# Package configuration
# ======================================================================

# ======================================================================
# Targets
# ======================================================================
add_executable(Arkanoid
    src/Main.cpp)

# ======================================================================
# Summary
# ======================================================================
message(STATUS "=== ${PROJECT_NAME} ===")
message(STATUS "C++ Version         : ${CMAKE_CXX_STANDARD}")
message(STATUS "C++ Compilar Flags  : ${CMAKE_CXX_FLAGS}")
message(STATUS "CMake build type    : ${CMAKE_BUILD_TYPE}")
message(STATUS "=== >>>><<<< ===")