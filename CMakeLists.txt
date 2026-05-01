cmake_minimum_required(VERSION 3.23)

project(Stepper_Dev_Kit)

# Parameters
option(MY_BUILD_DEMOS "Build Demos" OFF)
option(MY_BUILD_TESTS "Build Tests" OFF)

# Subdirectories
add_subdirectory(src)

# Demo
if(MY_BUILD_DEMOS)
    add_subdirectory(demos)
endif()

# Test
if(MY_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
