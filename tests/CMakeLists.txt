cmake_minimum_required(VERSION 3.23)

project(Tests)

enable_testing()

file(GLOB C_FILES CONFIGURE_DEPENDS "*.c")
file(GLOB H_FILES CONFIGURE_DEPENDS "*.h")

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_BINARY_DIR}/cxs_stepper_dev_kit
)

function(AddTest option)
    set(OPTION_TARGET "test_${option}")

    add_executable(${OPTION_TARGET})

    target_compile_options(
        ${OPTION_TARGET}
        PRIVATE
            -Wall
            -Werror
            -O2
    )

    target_link_libraries(
        ${OPTION_TARGET}
        PRIVATE
            cxs_stepper_dev_kit
    )

    target_sources(
        ${OPTION_TARGET}
        PRIVATE
            ${option}.c
        PUBLIC
            FILE_SET HEADERS
            TYPE HEADERS
            BASE_DIRS
                ${CMAKE_CURRENT_SOURCE_DIR}
            FILES
                ${H_FILES}
    )

    target_precompile_headers(
        ${OPTION_TARGET}
        PUBLIC
            ${H_FILES}
    )

    target_link_libraries(
        ${OPTION_TARGET}
        PRIVATE
            cxs_stepper_dev_kit
    )

    find_library(m m)
    if(m)
        target_link_libraries(
            ${OPTION_TARGET}
            PRIVATE
                m
        )
    endif()

    add_test(
        NAME ${option}
        COMMAND ${OPTION_TARGET}
    )
endfunction()

foreach(file_path IN LISTS C_FILES)
    cmake_path(GET file_path STEM file_stem)
    AddTest(${file_stem})
endforeach()
