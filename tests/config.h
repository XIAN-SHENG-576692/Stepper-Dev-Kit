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

#define PHASES 4

#define AMPLITUDE_PRECISION 4

    typedef uint16_t pulse_results_t;

    typedef struct
    {
        uint8_t values[PHASES];
    } amplitude_results_t;

    static inline uint8_t calc_amplitude_sine(float value)
    {
        return 0xFF * sin(value * M_PI_2);
    }

#ifdef __cplusplus
}
#endif
