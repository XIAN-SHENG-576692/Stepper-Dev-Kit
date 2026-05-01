/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#include "config.h"

int main(int argc, char *argv[])
{
    sine_results_t sine_results = {0};

    CXS_STEPPER_DEV_KIT_sine_t stepper_sine = {
        .step_to_value = step_to_value,
        .phase         = PHASES,
        .precision     = SINE_PRECISION,
    };

    pulse_results_t targets[PHASES * SINE_PRECISION][PHASES] = {
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

    uint16_t total =
        CXS_STEPPER_DEV_KIT_PASS_get_micro_step_drive_total_steps(&stepper_sine
        );

    for (uint16_t i = 0; i < total; i++)
    {
        CXS_STEPPER_DEV_KIT_sine_results_t params = {
            .index   = i,
            .stepper = &stepper_sine,
            .results = (uint8_t *)&sine_results,
        };
        CXS_STEPPER_DEV_KIT_PASS_micro_step_drive(&params);
        for (size_t j = 0; j < stepper_sine.phase; j++)
        {
            if (targets[i][j] != sine_results.values[j])
                return 1;
        }
    }

    return 0;
}
