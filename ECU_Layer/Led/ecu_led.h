/* 
 * File:   ecu_led.h
 * Author: mahdy
 *
 * Created on August 2, 2023, 3:07 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section : Includes */
#include "../../Mcal_Layer/mcal_std_types.h"
#include "../../Mcal_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum
{
    LED_OFF = 0,
    LED_ON   
}led_status_t;

typedef struct
{
    uint8 port   : 4;
    uint8 pin    : 3;
    uint8 status : 1;
}led_t;
/* Section : Function Prototype */

Std_ReturnType led_initialization(const led_t * _led_config);
Std_ReturnType led_on(const led_t * _led_config);
Std_ReturnType led_off(const led_t * _led_config);
Std_ReturnType led_toggle(const led_t * _led_config);
#endif	/* ECU_LED_H */

