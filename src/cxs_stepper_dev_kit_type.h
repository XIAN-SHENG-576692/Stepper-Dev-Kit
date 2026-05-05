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

#include <stdint.h>

    typedef struct
    {
        uint8_t phase;
    } CXS_STEPPER_DEV_KIT_pulse_t;

    /**
     * @brief A function that calculates amplitude based on a given value.
     *
     * @param value The ratio of index to max.
     *
     * @return The amplitude.
     *
     * @note
     * Example:
     * ```c
     * uint8_t calc_amplitude_fn(float value)
     * {
     *     return 0xFF * sin(value * M_PI_2);
     * }
     * ```
     */
    typedef uint8_t (*CXS_STEPPER_DEV_KIT_calc_amplitude_fn)(float value);

    typedef struct
    {
        uint8_t                               phase;
        uint8_t                               precision;
        CXS_STEPPER_DEV_KIT_calc_amplitude_fn calc_amplitude;
    } CXS_STEPPER_DEV_KIT_amplitude_t;

#ifdef __cplusplus
}
#endif
