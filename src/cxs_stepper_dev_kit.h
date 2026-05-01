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
        uint8_t  index;
        uint8_t  phase;
        uint8_t *results;
    } CXS_STEPPER_DEV_KIT_pulse_t;

#define CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS                             \
    uint8_t index, uint8_t phase, uint8_t *results

#define CXS_STEPPER_DEV_KIT_pulse_t_PASS_PARAMS(t) t.index, t.phase, t.results

    // ==================================================
    // Sine Wave

    typedef struct
    {
        uint16_t index;
        uint8_t  phase;
        uint8_t  precision;
        uint8_t (*index_to_sine)(uint8_t i);
        uint8_t *results;
    } CXS_STEPPER_DEV_KIT_sine_t;

#define CXS_STEPPER_DEV_KIT_sine_t_DECLARE_PARAMS                              \
    uint16_t index, uint8_t phase, uint8_t precision,                          \
        uint8_t (*index_to_sine)(uint8_t i), uint8_t *results

#define CXS_STEPPER_DEV_KIT_sine_t_PASS_PARAMS(t)                              \
    t.index, t.phase, t.precision, t.index_to_sine, t.results

    inline void CXS_STEPPER_DEV_KIT_full_step_drive(
        CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS
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

    inline void CXS_STEPPER_DEV_KIT_half_step_drive(
        CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS
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

    inline void CXS_STEPPER_DEV_KIT_micro_step_drive(
        CXS_STEPPER_DEV_KIT_sine_t_DECLARE_PARAMS
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
                // Decaying index_to_sine wave: sin(90 down to 0)
                val = index_to_sine(precision - step_index);
            }
            // Next phase in the cycle
            else if (i == (phase_offset + 1) % phase)
            {
                // Rising index_to_sine wave: sin(0 up to 90)
                val = index_to_sine(step_index);
            }

            results[i] = val;
        }

        return;
    }

    inline void
    CXS_STEPPER_DEV_KIT_wave_drive(CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS)
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
