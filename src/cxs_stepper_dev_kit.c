/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#include "cxs_stepper_dev_kit.h"

extern inline void CXS_STEPPER_DEV_KIT_full_step_drive(
    CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS
);
extern inline void CXS_STEPPER_DEV_KIT_half_step_drive(
    CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS
);
extern inline void CXS_STEPPER_DEV_KIT_micro_step_drive(
    CXS_STEPPER_DEV_KIT_sine_t_DECLARE_PARAMS
);
extern inline void
    CXS_STEPPER_DEV_KIT_wave_drive(CXS_STEPPER_DEV_KIT_pulse_t_DECLARE_PARAMS);
