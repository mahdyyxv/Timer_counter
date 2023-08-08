/* 
 * File:   ecu_dc_motor.h
 * Author: mahdy
 *
 * Created on August 6, 2023, 1:25 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes */
#include "../../Mcal_Layer/GPIO/hal_gpio.h"
#include "ecu_dc_motor_cfg.h"
/* Section : Macro Declarations */
#define DC_MOTOR_ON_STATE       0x00U
#define DC_MOTOR_OFF_STATE      0x01U
#define DC_MOTOR_PIN1           0x00U
#define DC_MOTOR_PIN2           0x01U
/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

typedef struct
{
    uint8 port      : 3;
    uint8 pin       : 3;
    uint8 status    : 1;
    uint8 reserved  : 1;
}dc_motor_pin_t;
typedef struct
{
    pin_config_t motor[2];
}dc_motor_t;
/* Section : Function Prototype */

Std_ReturnType  dc_motor_initialization(const dc_motor_t *motor_config);
Std_ReturnType  dc_motor_move_left(const dc_motor_t *motor_config);
Std_ReturnType  dc_motor_move_right(const dc_motor_t *motor_config);
Std_ReturnType  dc_motor_move_stop(const dc_motor_t *motor_config);
#endif	/* ECU_DC_MOTOR_H */

