cmake_minimum_required(VERSION 3.23)

project(Stepper_Dev_Kit)

if(NOT TARGET cxs_stepper_dev_kit)
    add_library(cxs_stepper_dev_kit)
endif()

add_subdirectory(include)
add_subdirectory(src)
