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
        0b1100,
        0b0110,
        0b0011,
        0b1001,
    // clang-format on
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        // clang-format off
        0b0011,
        0b0110,
        0b1100,
        0b1001,
    // clang-format on
#else
    #error "Cannot determine endianness"
#endif
    };

    for (uint8_t i = 0; i < stepper_pulse.phase; i++)
    {
        CXS_STEPPER_DEV_KIT_pulse_params_t params = {
            .index   = i,
            .stepper = &stepper_pulse,
            .results = (uint8_t *)&pulse_results,
        };
        CXS_STEPPER_DEV_KIT_PASS_full_step_drive(&params);
        if (targets[i] ^ pulse_results)
            return 1;
    }

    return 0;
}
