if(NOT TARGET cxs_stepper_dev_kit)
    add_library(cxs_stepper_dev_kit)
endif()

file(GLOB C_FILES CONFIGURE_DEPENDS "*.c")
file(GLOB H_FILES CONFIGURE_DEPENDS "*.h")

target_sources(
    cxs_stepper_dev_kit
    PRIVATE
        ${C_FILES}
    PUBLIC
        FILE_SET HEADERS
        TYPE HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
            ${H_FILES}
)

target_precompile_headers(
    cxs_stepper_dev_kit
    PUBLIC
        ${H_FILES}
)

target_include_directories(
    cxs_stepper_dev_kit
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:>
)
