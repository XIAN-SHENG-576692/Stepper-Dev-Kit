/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#include "config.h"

int main(int argc, char *argv[])
{
    amplitude_results_t amplitude_results = {0};

    CXS_STEPPER_DEV_KIT_amplitude_t stepper_amplitude = {
        .calc_amplitude = calc_amplitude_sine,
        .phase          = PHASES,
        .precision      = AMPLITUDE_PRECISION,
    };

    pulse_results_t targets[PHASES * AMPLITUDE_PRECISION][PHASES] = {
  // clang-format off
        { 0xFF, 0x00, 0x00, 0x00, },
        { 0xEB, 0x61, 0x00, 0x00, },   
        { 0xB4, 0xB4, 0x00, 0x00, },
        { 0x61, 0xEB, 0x00, 0x00, },
        { 0x00, 0xFF, 0x00, 0x00, },
        { 0x00, 0xEB, 0x61, 0x00, },
        { 0x00, 0xB4, 0xB4, 0x00, },
        { 0x00, 0x61, 0xEB, 0x00, },
        { 0x00, 0x00, 0xFF, 0x00, },
        { 0x00, 0x00, 0xEB, 0x61, },
        { 0x00, 0x00, 0xB4, 0xB4, },
        { 0x00, 0x00, 0x61, 0xEB, },
        { 0x00, 0x00, 0x00, 0xFF, },
        { 0x61, 0x00, 0x00, 0xEB, },
        { 0xB4, 0x00, 0x00, 0xB4, },
        { 0xEB, 0x00, 0x00, 0x61, },
  // clang-format on
    };

    uint16_t total = CXS_STEPPER_DEV_KIT_PASS_get_micro_step_drive_total_steps(
        &stepper_amplitude
    );

    for (uint16_t i = 0; i < total; i++)
    {
        CXS_STEPPER_DEV_KIT_amplitude_results_t params = {
            .index   = i,
            .stepper = &stepper_amplitude,
            .results = (uint8_t *)&amplitude_results,
        };
        CXS_STEPPER_DEV_KIT_PASS_micro_step_drive(&params);
        for (size_t j = 0; j < stepper_amplitude.phase; j++)
        {
            if (targets[i][j] != amplitude_results.values[j])
                return 1;
        }
    }

    return 0;
}
