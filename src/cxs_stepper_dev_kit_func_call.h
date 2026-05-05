#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include "cxs_stepper_dev_kit_func.h"
    typedef struct
    {
        uint8_t byte_index;
        uint8_t phase;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_full_step_drive_args__;
    inline uint8_t __CXS_STEPPER_DEV_KIT_full_step_drive_call__(
        const __CXS_STEPPER_DEV_KIT_full_step_drive_args__ *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_full_step_drive(
            args->byte_index,
            args->phase,
            args->step_index
        );
    };
#define CXS_STEPPER_DEV_KIT_full_step_drive_call(...)                          \
    __CXS_STEPPER_DEV_KIT_full_step_drive_call__(                              \
        &(const __CXS_STEPPER_DEV_KIT_full_step_drive_args__){__VA_ARGS__}     \
    )
    typedef struct
    {
        uint8_t phase;
    } __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_args__;
    inline uint16_t
    __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_call__(
        const __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_args__
            *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps(args->phase);
    };
#define CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_call(...)          \
    __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_call__(&(            \
        const __CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps_args__     \
    ){__VA_ARGS__})
    typedef struct
    {
        uint8_t phase;
        uint8_t precision;
    } __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_args__;
    inline uint16_t
    __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_call__(
        const __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_args__
            *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(
            args->phase,
            args->precision
        );
    };
#define CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_call(...)         \
    __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_call__(&(           \
        const __CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps_args__    \
    ){__VA_ARGS__})
    typedef struct
    {
        uint8_t byte_index;
        uint8_t phase;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_half_step_drive_args__;
    inline uint8_t __CXS_STEPPER_DEV_KIT_half_step_drive_call__(
        const __CXS_STEPPER_DEV_KIT_half_step_drive_args__ *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_half_step_drive(
            args->byte_index,
            args->phase,
            args->step_index
        );
    };
#define CXS_STEPPER_DEV_KIT_half_step_drive_call(...)                          \
    __CXS_STEPPER_DEV_KIT_half_step_drive_call__(                              \
        &(const __CXS_STEPPER_DEV_KIT_half_step_drive_args__){__VA_ARGS__}     \
    )
    typedef struct
    {
        CXS_STEPPER_DEV_KIT_calc_amplitude_fn calc_amplitude;
        uint8_t                               phase;
        uint8_t                               phase_index;
        uint8_t                               precision;
        uint16_t                              step_index;
    } __CXS_STEPPER_DEV_KIT_micro_step_drive_args__;
    inline uint8_t __CXS_STEPPER_DEV_KIT_micro_step_drive_call__(
        const __CXS_STEPPER_DEV_KIT_micro_step_drive_args__ *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_micro_step_drive(
            args->calc_amplitude,
            args->phase,
            args->phase_index,
            args->precision,
            args->step_index
        );
    };
#define CXS_STEPPER_DEV_KIT_micro_step_drive_call(...)                         \
    __CXS_STEPPER_DEV_KIT_micro_step_drive_call__(                             \
        &(const __CXS_STEPPER_DEV_KIT_micro_step_drive_args__){__VA_ARGS__}    \
    )
    typedef struct
    {
        uint8_t byte_index;
        uint8_t phase;
        uint8_t step_index;
    } __CXS_STEPPER_DEV_KIT_wave_drive_args__;
    inline uint8_t __CXS_STEPPER_DEV_KIT_wave_drive_call__(
        const __CXS_STEPPER_DEV_KIT_wave_drive_args__ *const args
    )
    {
        return CXS_STEPPER_DEV_KIT_wave_drive(
            args->byte_index,
            args->phase,
            args->step_index
        );
    };
#define CXS_STEPPER_DEV_KIT_wave_drive_call(...)                               \
    __CXS_STEPPER_DEV_KIT_wave_drive_call__(                                   \
        &(const __CXS_STEPPER_DEV_KIT_wave_drive_args__){__VA_ARGS__}          \
    )
#ifdef __cplusplus
}
#endif
