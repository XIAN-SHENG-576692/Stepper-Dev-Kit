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

    printf("PHASES:    %3d\n", stepper_sine.phase);
    printf("PRECISION: %3d\n", stepper_sine.precision);

    printf("SINE: \n");
    for (size_t i = 0; i < SINE_PRECISION; i++)
    {
        printf("0x%02X\n", stepper_sine.step_to_value(i));
    }

    printf("Resutls: \n");
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
            printf("0x%02X,", sine_results.values[j]);
        }
        printf("\n");
    }

    return 0;
}
