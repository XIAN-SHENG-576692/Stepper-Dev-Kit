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

    pulse_results_t targets[PHASES * 2] = {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        // clang-format off
        0b1000,
        0b1100,
        0b0100,
        0b0110,
        0b0010,
        0b0011,
        0b0001,
        0b1001,
    // clang-format on
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        // clang-format off
        0b0001,
        0b0011,
        0b0010,
        0b0110,
        0b0100,
        0b1100,
        0b1000,
        0b1001,
    // clang-format on
#else
    #error "Cannot determine endianness"
#endif
    };

    uint8_t total =
        CXS_STEPPER_DEV_KIT_PASS_get_half_step_drive_total_steps(&stepper_pulse
        );

    for (uint8_t i = 0; i < total; i++)
    {
        CXS_STEPPER_DEV_KIT_pulse_params_t params = {
            .index   = i,
            .stepper = &stepper_pulse,
            .results = (uint8_t *)&pulse_results,
        };
        CXS_STEPPER_DEV_KIT_PASS_half_step_drive(&params);
        if (targets[i] ^ pulse_results)
            return 1;
    }

    return 0;
}
