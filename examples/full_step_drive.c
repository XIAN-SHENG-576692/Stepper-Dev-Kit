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
    CXS_STEPPER_DEV_KIT_pulse_params_t params = {
        .result_index = 0,
        .step_index   = 0,
        .stepper      = &stepper_pulse,
    };
#define i params.step_index
    for (i = 0; i < stepper_pulse.phase; i++)
    {
#define j params.result_index
        for (j = 0; j < (stepper_pulse.phase + 7) / 8; j++)
        {
            ((uint8_t *)&pulse_results)[j] =
                CXS_STEPPER_DEV_KIT_PASS_full_step_drive(&params);
        }
        printf("%0" STRINGIZE_THIS_DEFINITION(PHASES) "b\n", pulse_results);
#undef j
    }
#undef i

    return 0;
}
