/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#include "config.h"

int main(int argc, char *argv[])
{
    pulse_results_t pulse_results = {0};

    CXS_STEPPER_DEV_KIT_pulse_t stepper_pulse = {
        .phase = PHASES,
    };

    pulse_results_t targets[PHASES] = {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        // clang-format off
        0b10000000,
        0b01000000,
        0b00100000,
        0b00010000,
    // clang-format on
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        // clang-format off
        0b0001,
        0b0010,
        0b0100,
        0b1000,
    // clang-format on
#else
    #error "Cannot determine endianness"
#endif
    };

    for (uint8_t i = 0; i < stepper_pulse.phase; i++)
    {
        for (uint8_t j = 0; j < (stepper_pulse.phase + 7) / 8; j++)
        {
            ((uint8_t *)&pulse_results)[j] =
                CXS_STEPPER_DEV_KIT_wave_drive_call(
                        .byte_index = j,
                        .phase      = stepper_pulse.phase,
                        .step_index = i,
                );
        }
        if (targets[i] ^ pulse_results)
            return 1;
    }

    return 0;
}
