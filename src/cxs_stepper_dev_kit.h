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
        uint8_t (*calc_amplitude)(float value); // Example: 0xFF * sin(value * M_PI_2);
    } CXS_STEPPER_DEV_KIT_amplitude_t;

    // ==================================================
    // Function

    typedef struct
    {
        CXS_STEPPER_DEV_KIT_pulse_t *stepper;
        uint8_t                      index;
        uint8_t                     *results;
    } CXS_STEPPER_DEV_KIT_pulse_results_t;

    typedef struct
    {
        CXS_STEPPER_DEV_KIT_amplitude_t *stepper;
        uint16_t                         index;
        uint8_t                         *results;
    } CXS_STEPPER_DEV_KIT_amplitude_results_t;

#define CXS_STEPPER_DEV_KIT_PASS_full_step_drive(t)                            \
    CXS_STEPPER_DEV_KIT_full_step_drive(                                       \
        (t)->index,                                                            \
        (t)->stepper->phase,                                                   \
        (t)->results                                                           \
    )
    inline void CXS_STEPPER_DEV_KIT_full_step_drive(
        uint8_t  index,
        uint8_t  phase,
        uint8_t *results
    )
    {
        for (size_t i = 0; i < phase; i++)
        {
            if ((i == index % phase) || (i == (index + 1) % phase))
            {
                results[i / 8] |= 1 << (i % 8);
            }
            else
            {
                results[i / 8] &= ~(1 << (i % 8));
            }
        }
        return;
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
        (t)->index,                                                            \
        (t)->stepper->phase,                                                   \
        (t)->results                                                           \
    )
    inline void CXS_STEPPER_DEV_KIT_half_step_drive(
        uint8_t  index,
        uint8_t  phase,
        uint8_t *results
    )
    {
        uint8_t half_index = (uint8_t)(index / 2);
        for (size_t i = 0; i < phase; i++)
        {
            if ((i == half_index % phase) ||
                (((index % 2) == 1) && (i == (half_index + 1) % phase)))
            {
                results[i / 8] |= 1 << (i % 8);
            }
            else
            {
                results[i / 8] &= ~(1 << (i % 8));
            }
        }
        return;
    }

#define CXS_STEPPER_DEV_KIT_PASS_micro_step_drive(t)                           \
    CXS_STEPPER_DEV_KIT_micro_step_drive(                                      \
        (t)->index,                                                            \
        (t)->stepper->phase,                                                   \
        (t)->stepper->precision,                                               \
        (t)->stepper->calc_amplitude,                                          \
        (t)->results                                                           \
    )
    inline void CXS_STEPPER_DEV_KIT_micro_step_drive(
        uint16_t index,
        uint8_t  phase,
        uint8_t  precision,
        uint8_t (*calc_amplitude)(float value),
        uint8_t *results
    )
    {
        // The current full-step is determined by (index / precision)
        // The micro-step progress within that step is (index % precision)
        uint8_t step_index   = index % precision;
        uint8_t phase_offset = (index / precision) % phase;

        for (size_t i = 0; i < phase; i++)
        {
            uint8_t val = 0;

            // Current phase in the cycle
            if (i == phase_offset)
            {
                // Decaying calc_amplitude wave: peak down 0
                val =
                    calc_amplitude((float)(precision - step_index) / precision);
            }
            // Next phase in the cycle
            else if (i == (phase_offset + 1) % phase)
            {
                // Rising calc_amplitude wave: 0 up to peak
                val = calc_amplitude((float)step_index / precision);
            }

            results[i] = val;
        }

        return;
    }

#define CXS_STEPPER_DEV_KIT_PASS_wave_drive(t)                                 \
    CXS_STEPPER_DEV_KIT_wave_drive(                                            \
        (t)->index,                                                            \
        (t)->stepper->phase,                                                   \
        (t)->results                                                           \
    )
    inline void CXS_STEPPER_DEV_KIT_wave_drive(
        uint8_t  index,
        uint8_t  phase,
        uint8_t *results
    )
    {
        for (size_t i = 0; i < phase; i++)
        {
            if (i == index % phase)
            {
                results[i / 8] |= 1 << (i % 8);
            }
            else
            {
                results[i / 8] &= ~(1 << (i % 8));
            }
        }
        return;
    }

#ifdef __cplusplus
}
#endif
