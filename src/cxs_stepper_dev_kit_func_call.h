#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include "cxs_stepper_dev_kit_func.h"
    typedef struct
    {
        uint8_t phase;
        uint8_t result_index;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_full_step_drive_args__;
#define CXS_STEPPER_DEV_KIT_full_step_drive_call(...)                          \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_full_step_drive_args__ args = {__VA_ARGS__};     \
        CXS_STEPPER_DEV_KIT_full_step_drive(                                   \
            args.phase,                                                        \
            args.result_index,                                                 \
            args.step_index                                                    \
        );                                                                     \
    })
    typedef struct
    {
        uint8_t phase;
    } __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_args__;
#define CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_call(...)          \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_args__ args = {  \
            __VA_ARGS__};                                                      \
        CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps(args.phase);       \
    })
    typedef struct
    {
        uint8_t phase;
        uint8_t precision;
    } __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_args__;
#define CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_call(...)         \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_args__ args = { \
            __VA_ARGS__};                                                      \
        CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(                  \
            args.phase,                                                        \
            args.precision                                                     \
        );                                                                     \
    })
    typedef struct
    {
        uint8_t phase;
        uint8_t result_index;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_half_step_drive_args__;
#define CXS_STEPPER_DEV_KIT_half_step_drive_call(...)                          \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_half_step_drive_args__ args = {__VA_ARGS__};     \
        CXS_STEPPER_DEV_KIT_half_step_drive(                                   \
            args.phase,                                                        \
            args.result_index,                                                 \
            args.step_index                                                    \
        );                                                                     \
    })
    typedef struct
    {
        CXS_STEPPER_DEV_KIT_calc_amplitude_fn calc_amplitude;
        uint8_t                               phase;
        uint8_t                               phase_index;
        uint8_t                               precision;
        uint16_t                              step_index;
    } __CXS_STEPPER_DEV_KIT_micro_step_drive_args__;
#define CXS_STEPPER_DEV_KIT_micro_step_drive_call(...)                         \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_micro_step_drive_args__ args = {__VA_ARGS__};    \
        CXS_STEPPER_DEV_KIT_micro_step_drive(                                  \
            args.calc_amplitude,                                               \
            args.phase,                                                        \
            args.phase_index,                                                  \
            args.precision,                                                    \
            args.step_index                                                    \
        );                                                                     \
    })
    typedef struct
    {
        uint8_t phase;
        uint8_t result_index;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_wave_drive_args__;
#define CXS_STEPPER_DEV_KIT_wave_drive_call(...)                               \
    ({                                                                         \
        __CXS_STEPPER_DEV_KIT_wave_drive_args__ args = {__VA_ARGS__};          \
        CXS_STEPPER_DEV_KIT_wave_drive(                                        \
            args.phase,                                                        \
            args.result_index,                                                 \
            args.step_index                                                    \
        );                                                                     \
    })
#ifdef __cplusplus
}
#endif
