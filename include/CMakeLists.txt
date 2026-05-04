file(GLOB H_FILES CONFIGURE_DEPENDS "*.h")

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
