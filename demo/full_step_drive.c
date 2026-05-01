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
        .index   = 0,
        .phase   = PHASES,
        .results = (uint8_t *)&pulse_results,
    };

    printf("PHASES: %2d\n", stepper_pulse.phase);

    printf("Resutls: \n");
#define i (stepper_pulse.index)
    for (i = 0; i < stepper_pulse.phase; i++)
    {
        CXS_STEPPER_DEV_KIT_full_step_drive(
            CXS_STEPPER_DEV_KIT_pulse_t_PASS_PARAMS(stepper_pulse)
        );
        printf("%0" STRINGIZE_THIS_DEFINITION(PHASES) "b\n", pulse_results);
    }
#undef i

    return 0;
}
