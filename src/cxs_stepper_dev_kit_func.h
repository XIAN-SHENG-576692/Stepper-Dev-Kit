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

#include "cxs_stepper_dev_kit_type.h"

/**
 * @brief Map the byte index to the equivalent step index.
 *
 * @param byte_index The byte index
 * @return The step index
 *
 * @note
 * ```latex
 * \begin{math}
 * byte_index \times 8
 * \end{math}
 * ```
 */
#define __byte_index_to_step_index(byte_index) (byte_index << 3)

    inline uint8_t CXS_STEPPER_DEV_KIT_full_step_drive(
        uint8_t byte_index,
        uint8_t phase,
        uint8_t step_index
    )
    {
#define __result0 (step_index - __byte_index_to_step_index(byte_index))
#define __result1                                                              \
    (((step_index + 1) % phase) - __byte_index_to_step_index(byte_index))
        return ((__result0 >= 0) ? 1 << __result0 : 0) |
               ((__result1 >= 0) ? 1 << __result1 : 0);
#undef __result1
#undef __result0
    }

    /**
     * @brief Get the total number of steps for half-step drive.
     *
     * @param phase The number of phases
     * @return The total number of steps
     *
     * @note
     * ```latex
     * \begin{math}
     * phase \times 2
     * \end{math}
     * ```
     */
    inline uint16_t
    CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps(uint8_t phase)
    {
        return phase << 1;
    }

    /**
     * @brief Get the total number of steps for micro-step drive.
     *
     * @param phase The number of phases
     * @param precision The precision of amplitude
     * @return The total number of steps
     *
     * @note
     * ```latex
     * \begin{math}
     * phase \times precision
     * \end{math}
     * ```
     */
    inline uint16_t CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(
        uint8_t phase,
        uint8_t precision
    )
    {
        return phase * precision;
    }

    inline uint8_t CXS_STEPPER_DEV_KIT_half_step_drive(
        uint8_t byte_index,
        uint8_t phase,
        uint8_t step_index
    )
    {
#define __half_index (step_index / 2)
#define __result0    (__half_index - __byte_index_to_step_index(byte_index))
#define __result1                                                              \
    (((step_index % 2) == 1) ? (((__half_index + 1) % phase) -                 \
                                __byte_index_to_step_index(byte_index))        \
                             : -1)
        return ((__result0 >= 0) ? 1 << __result0 : 0) |
               ((__result1 >= 0) ? 1 << __result1 : 0);
#undef __result1
#undef __result0
#undef __half_index
    }

    inline uint8_t CXS_STEPPER_DEV_KIT_micro_step_drive(
        CXS_STEPPER_DEV_KIT_calc_amplitude_fn calc_amplitude,
        uint8_t                               phase,
        uint8_t                               phase_index,
        uint8_t                               precision,
        uint16_t                              step_index
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

    inline uint8_t CXS_STEPPER_DEV_KIT_wave_drive(
        uint8_t byte_index,
        uint8_t phase,
        uint8_t step_index
    )
    {
#define __result (step_index - __byte_index_to_step_index(byte_index))
        return ((__result >= 0) ? 1 << __result : 0);
#undef __result
    }

#undef __byte_index_to_step_index

#ifdef __cplusplus
}
#endif
