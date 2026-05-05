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

    printf("PHASES: %2d\n", stepper_pulse.phase);

    printf("RESULTS: \n");

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
        printf("%0" STRINGIZE_THIS_DEFINITION(PHASES) "b\n", pulse_results);
    }

    return 0;
}
