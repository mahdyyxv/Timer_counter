/* 
 * File:   ecu_relay.h
 * Author: mahdy
 *
 * Created on August 6, 2023, 10:36 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes */
#include "../../Mcal_Layer/GPIO/hal_gpio.h"
#include "ecu_relay_cfg.h"
/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum {
    RELAY_STATE_OFF,
    RELAY_STATE_ON
}relay_state_t;

typedef struct
{
    uint8 port              : 3;
    uint8 pin               : 3;
    uint8 status            : 1;
    uint8 reserved          : 1;
}relay_t;
/* Section : Function Prototype */
Std_ReturnType relay_initialization(const relay_t *relay_config);
Std_ReturnType relay_on(const relay_t *relay_config);
Std_ReturnType relay_off(const relay_t *relay_config);

#endif	/* ECU_RELAY_H */

