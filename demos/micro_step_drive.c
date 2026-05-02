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

    printf("PHASES:    %3d\n", stepper_amplitude.phase);
    printf("PRECISION: %3d\n", stepper_amplitude.precision);

    printf("SINE: \n");
    for (size_t i = 0; i < AMPLITUDE_PRECISION; i++)
    {
        printf(
            "0x%02X\n",
            stepper_amplitude.calc_amplitude((float)i / AMPLITUDE_PRECISION)
        );
    }

    printf("RESULTS: \n");
    uint16_t total = CXS_STEPPER_DEV_KIT_PASS_get_micro_step_drive_total_steps(
        &stepper_amplitude
    );

    CXS_STEPPER_DEV_KIT_amplitude_params_t params = {
        .phase_index = 0,
        .step_index  = 0,
        .stepper     = &stepper_amplitude,
    };
#define i params.step_index
    for (i = 0; i < total; i++)
    {
#define j params.phase_index
        for (j = 0; j < stepper_amplitude.phase; j++)
        {
            amplitude_results.values[j] =
                CXS_STEPPER_DEV_KIT_PASS_micro_step_drive(&params);
            printf("0x%02X,", amplitude_results.values[j]);
        }
        printf("\n");
#undef j
    }
#undef i

    return 0;
}
