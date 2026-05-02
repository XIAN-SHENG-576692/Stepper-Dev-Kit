/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

    // ==================================================
    // Pulse Wave

    typedef struct
    {
        uint8_t phase;
    } CXS_STEPPER_DEV_KIT_pulse_t;

    // ==================================================
    // Amplitude Wave

    typedef struct
    {
        uint8_t phase;
        uint8_t precision;
        uint8_t (*calc_amplitude)(float value
        ); // Example: 0xFF * sin(value * M_PI_2);
    } CXS_STEPPER_DEV_KIT_amplitude_t;

    // ==================================================
    // Function

    typedef struct
    {
        CXS_STEPPER_DEV_KIT_pulse_t *stepper;
        uint8_t                      step_index;
        uint8_t                      result_index;
    } CXS_STEPPER_DEV_KIT_pulse_params_t;

    typedef struct
    {
        CXS_STEPPER_DEV_KIT_amplitude_t *stepper;
        uint16_t                         step_index;
        uint8_t                          phase_index;
    } CXS_STEPPER_DEV_KIT_amplitude_params_t;

#define CXS_STEPPER_DEV_KIT_PASS_full_step_drive(t)                            \
    CXS_STEPPER_DEV_KIT_full_step_drive(                                       \
        (t)->stepper->phase,                                                   \
        (t)->result_index,                                                     \
        (t)->step_index                                                        \
    )
    inline uint8_t CXS_STEPPER_DEV_KIT_full_step_drive(
        uint8_t phase,
        uint8_t result_index,
        uint8_t step_index
    )
    {
#define __result0 (step_index - (result_index * 8))
#define __result1 (((step_index + 1) % phase) - (result_index * 8))
        return ((__result0 >= 0) ? 1 << __result0 : 0) |
               ((__result1 >= 0) ? 1 << __result1 : 0);
#undef __result1
#undef __result0
    }

#define CXS_STEPPER_DEV_KIT_PASS_get_half_step_drive_total_steps(t)            \
    CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps((t)->phase)
    inline uint8_t
    CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps(uint8_t phase)
    {
        return phase * 2;
    }

#define CXS_STEPPER_DEV_KIT_PASS_get_micro_step_drive_total_steps(t)           \
    CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(                      \
        (t)->phase,                                                            \
        (t)->precision                                                         \
    )
    inline uint16_t CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(
        uint8_t phase,
        uint8_t precision
    )
    {
        return phase * precision;
    }

#define CXS_STEPPER_DEV_KIT_PASS_half_step_drive(t)                            \
    CXS_STEPPER_DEV_KIT_half_step_drive(                                       \
        (t)->stepper->phase,                                                   \
        (t)->result_index,                                                     \
        (t)->step_index                                                        \
    )
    inline uint8_t CXS_STEPPER_DEV_KIT_half_step_drive(
        uint8_t phase,
        uint8_t result_index,
        uint8_t step_index
    )
    {
#define __half_index (step_index / 2)
#define __result0    (__half_index - (result_index * 8))
#define __result1                                                              \
    (((step_index % 2) == 1)                                                   \
         ? (((__half_index + 1) % phase) - (result_index * 8))                 \
         : -1)
        return ((__result0 >= 0) ? 1 << __result0 : 0) |
               ((__result1 >= 0) ? 1 << __result1 : 0);
#undef __result1
#undef __result0
#undef __half_index
    }

#define CXS_STEPPER_DEV_KIT_PASS_micro_step_drive(t)                           \
    CXS_STEPPER_DEV_KIT_micro_step_drive(                                      \
        (t)->stepper->calc_amplitude,                                          \
        (t)->stepper->phase,                                                   \
        (t)->phase_index,                                                      \
        (t)->stepper->precision,                                               \
        (t)->step_index                                                        \
    )
    inline uint8_t CXS_STEPPER_DEV_KIT_micro_step_drive(
        uint8_t (*calc_amplitude)(float value),
        uint8_t  phase,
        uint8_t  phase_index,
        uint8_t  precision,
        uint16_t step_index
    )
    {
        // The current full-step is determined by (step_index / precision)
        // The micro-step progress within that step is (step_index % precision)
        uint8_t value_index  = step_index % precision;
        uint8_t phase_offset = (step_index / precision);

        // Current phase in the cycle
        if (phase_index == phase_offset)
        {
            // Decaying calc_amplitude wave: peak down 0
            return calc_amplitude((float)(precision - value_index) / precision);
        }
        // Next phase in the cycle
        else if (phase_index == (phase_offset + 1) % phase)
        {
            // Rising calc_amplitude wave: 0 up to peak
            return calc_amplitude((float)value_index / precision);
        }

        return 0x00;
    }

#define CXS_STEPPER_DEV_KIT_PASS_wave_drive(t)                                 \
    CXS_STEPPER_DEV_KIT_wave_drive(                                            \
        (t)->stepper->phase,                                                   \
        (t)->result_index,                                                     \
        (t)->step_index                                                        \
    )
    inline uint8_t CXS_STEPPER_DEV_KIT_wave_drive(
        uint8_t phase,
        uint8_t result_index,
        uint8_t step_index
    )
    {
#define __result (step_index - (result_index * 8))
        return ((__result >= 0) ? 1 << __result : 0);
#undef __result
    }

#ifdef __cplusplus
}
#endif
