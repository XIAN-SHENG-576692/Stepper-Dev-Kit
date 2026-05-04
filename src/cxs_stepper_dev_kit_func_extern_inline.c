#include "cxs_stepper_dev_kit_func.h"
extern inline uint8_t CXS_STEPPER_DEV_KIT_full_step_drive(
    uint8_t phase,
    uint8_t result_index,
    uint8_t step_index
);
extern inline uint16_t
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
    CXS_STEPPER_DEV_KIT_calc_amplitude_fn calc_amplitude,
    uint8_t                               phase,
    uint8_t                               phase_index,
    uint8_t                               precision,
    uint16_t                              step_index
);
extern inline uint8_t CXS_STEPPER_DEV_KIT_wave_drive(
    uint8_t phase,
    uint8_t result_index,
    uint8_t step_index
);
