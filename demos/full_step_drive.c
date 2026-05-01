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
        CXS_STEPPER_DEV_KIT_pulse_params_t params = {
            .index   = i,
            .stepper = &stepper_pulse,
            .results = (uint8_t *)&pulse_results,
        };
        CXS_STEPPER_DEV_KIT_PASS_full_step_drive(&params);
        printf("%0" STRINGIZE_THIS_DEFINITION(PHASES) "b\n", pulse_results);
    }

    return 0;
}
