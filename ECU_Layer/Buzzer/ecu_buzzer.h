/* 
 * File:   Buzzer.h
 * Author: mahdy
 *
 * Created on August 7, 2023, 5:48 PM
 */

#ifndef BUZZER_H
#define	BUZZER_H

/* Section : Includes */
#include "ecu_buzzer_cfg.h"
#include "../../Mcal_Layer/GPIO/hal_gpio.h"
/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum
{
    BUZZER_OFF,
    BUZZER_ON
}buzzer_status_t;

typedef struct
{
    pin_config_t    buzzer_pin;
}buzzer_t;
/* Section : Function Prototype */
Std_ReturnType buzzer_initialization(const buzzer_t *buzzer_config);
Std_ReturnType buzzer_on(const buzzer_t *buzzer_config);
Std_ReturnType buzzer_off(const buzzer_t *buzzer_config);
Std_ReturnType buzzer_beeb(const buzzer_t *buzzer_config);
#endif	/* BUZZER_H */

