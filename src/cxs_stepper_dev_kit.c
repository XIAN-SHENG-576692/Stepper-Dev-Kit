/**
 * @author    XIAN-SHENG CHEN
 * @date      April 2026
 *
 * Copyright (c) 2026 XIAN-SHENG CHEN. All Rights Reserved.
 **/
#include "cxs_stepper_dev_kit.h"

extern inline uint8_t CXS_STEPPER_DEV_KIT_full_step_drive(
    uint8_t phase,
    uint8_t result_index,
    uint8_t step_index
);
extern inline uint8_t
CXS_STEPPER_DEV_KIT_get_half_step_drive_total_steps(uint8_t phase);
extern inline uint16_t CXS_STEPPER_DEV_KIT_get_micro_step_drive_total_steps(
    uint8_t phase,
    uint8_t precision
);
extern inline uint8_t CXS_STEPPER_DEV_KIT_half_step_drive(
    uint8_t phase,
    uint8_t result_index,
    uint8_t step_index
);
extern inline uint8_t CXS_STEPPER_DEV_KIT_micro_step_drive(
    uint8_t (*calc_amplitude)(float value),
    uint8_t  phase,
    uint8_t  phase_index,
    uint8_t  precision,
    uint16_t step_index
);
extern inline uint8_t CXS_STEPPER_DEV_KIT_wave_drive(
    uint8_t phase,
    uint8_t result_index,
    uint8_t step_index
);
