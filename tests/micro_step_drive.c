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
        .index         = 0,
        .index_to_sine = index_to_sine,
        .phase         = PHASES,
        .precision     = SINE_PRECISION,
        .results       = (uint8_t *)&sine_results,
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
#define i (stepper_sine.index)
    for (i = 0; i < stepper_sine.phase * stepper_sine.precision; i++)
    {
        CXS_STEPPER_DEV_KIT_micro_step_drive(
            CXS_STEPPER_DEV_KIT_sine_t_PASS_PARAMS(stepper_sine)
        );
        for (size_t j = 0; j < stepper_sine.phase; j++)
        {
            if (targets[i][j] != sine_results.values[j])
                return 1;
        }
    }
#undef i

    return 0;
}
