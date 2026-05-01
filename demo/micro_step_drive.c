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

    printf("PHASES:    %3d\n", stepper_sine.phase);
    printf("PRECISION: %3d\n", stepper_sine.precision);

    printf("SINE: \n");
    for (size_t i = 0; i < SINE_PRECISION; i++)
    {
        printf("0x%02X\n", stepper_sine.index_to_sine(i));
    }

    printf("Resutls: \n");
#define i (stepper_sine.index)
    for (i = 0; i < stepper_sine.phase * stepper_sine.precision; i++)
    {
        CXS_STEPPER_DEV_KIT_micro_step_drive(
            CXS_STEPPER_DEV_KIT_sine_t_PASS_PARAMS(stepper_sine)
        );
        for (size_t j = 0; j < stepper_sine.phase; j++)
        {
            printf("0x%02X,", sine_results.values[j]);
        }
        printf("\n");
    }
#undef i

    return 0;
}
