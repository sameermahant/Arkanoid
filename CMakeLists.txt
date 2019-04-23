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

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'RelWithDebInfo' as none was specified.")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

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
