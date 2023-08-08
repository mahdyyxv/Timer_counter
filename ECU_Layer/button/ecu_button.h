/* 
 * File:   ecu_button.h
 * Author: mahdy
 *
 * Created on August 5, 2023, 3:23 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section : Includes */
#include "ecu_button_cfg.h"
/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */

typedef enum
{
    BUTTON_RELEASED,
    BUTTON_PRESSED
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH        
}button_active_t;

typedef struct
{
    pin_config_t btn_obj;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/* Section : Function Prototype */

Std_ReturnType  button_initialization(const button_t *btn);
Std_ReturnType  button_read_logic(const button_t *btn, button_state_t *state);


#endif	/* ECU_BUTTON_H */

