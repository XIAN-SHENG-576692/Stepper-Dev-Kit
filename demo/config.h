/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "cxs_stepper_dev_kit.h"

#define __USE_MISC
#include <math.h>
#include <stdio.h>

#define STRINGIZE_THIS(var)            #var
#define STRINGIZE_THIS_DEFINITION(var) STRINGIZE_THIS(var)

#define PHASES 16

#define SINE_PRECISION 16

    typedef uint16_t pulse_results_t;

    typedef struct
    {
        uint8_t values[PHASES];
    } sine_results_t;

    static inline uint8_t step_to_value(uint8_t i)
    {
        return 0xFF * sin(i * M_PI_2 / SINE_PRECISION);
    }

#ifdef __cplusplus
}
#endif
