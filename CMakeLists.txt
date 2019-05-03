# ======================================================================
# CMake mandatory command
# ======================================================================
cmake_minimum_required(VERSION 3.14)

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
set(SFML_INCLUDE_DIR "/opt/external/SFML-2.5.1/include")
set(SFML_LIB_DIR "/opt/external/SFML-2.5.1/lib")
set(LIB_STDCPP_DIR "/opt/external/libstdcpp64")

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
    src/Main.cpp
    src/Game.cpp
    src/Circle.cpp
    src/Ball.cpp
    src/Rectangle.cpp
    src/Paddle.cpp
    )

target_include_directories(Arkanoid PRIVATE ${SFML_INCLUDE_DIR})
target_link_directories(Arkanoid PRIVATE ${SFML_LIB_DIR})
target_link_libraries(Arkanoid PRIVATE sfml-system sfml-window sfml-graphics)
set_target_properties(Arkanoid PROPERTIES BUILD_RPATH "${SFML_LIB_DIR}")
#set_target_properties(Arkanoid PROPERTIES
#    INSTALL_RPATH ${LIB_STDCPP_DIR}
#    BUILD_WITH_INSTALL_RPATH TRUE)

# ======================================================================
# Summary
# ======================================================================
message(STATUS "=== ${PROJECT_NAME} ===")
message(STATUS "C++ Version         : ${CMAKE_CXX_STANDARD}")
message(STATUS "C++ Compilar Flags  : ${CMAKE_CXX_FLAGS}")
message(STATUS "CMake Build Type    : ${CMAKE_BUILD_TYPE}")
message(STATUS "=== >>>><<<< ===")
