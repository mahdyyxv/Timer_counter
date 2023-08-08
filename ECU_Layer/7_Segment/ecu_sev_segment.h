/* 
 * File:   ecu_sev_segment.h
 * Author: mahdy
 *
 * Created on August 7, 2023, 2:46 PM
 */

#ifndef ECU_SEV_SEGMENT_H
#define	ECU_SEV_SEGMENT_H

/* Section : Includes */

#include "ecu_sev_segment_cfg.h"
#include "../../Mcal_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct
{
    pin_config_t   segment_pins[4];
    segment_type_t segment_type;
}segment_t;
/* Section : Function Prototype */


Std_ReturnType seven_segment_initialize(const segment_t *seg_config);
Std_ReturnType seven_segment_write_number(const segment_t *seg_config, uint8 number);
#if SEGMENT_CONFIG==MULTIPLEXED
Std_ReturnType seven_segment_control_initialize(const pin_config_t *pin_config);
Std_ReturnType seven_segment_control_turn_on(const segment_t *seg_config, const pin_config_t *pin_config);
Std_ReturnType seven_segment_control_turn_off(const segment_t *seg_config, const pin_config_t *pin_config);
#endif
#endif	/* ECU_SEV_SEGMENT_H */

