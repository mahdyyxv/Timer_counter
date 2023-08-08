/* 
 * File:   application.h
 * Author: mahdy
 *
 * Created on August 2, 2023, 3:09 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "Mcal_Layer/GPIO/hal_gpio.h"
#include "ECU_Layer/Led/ecu_led.h"
#include "ECU_Layer/button/ecu_button.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"
#include "ECU_Layer/7_Segment/ecu_sev_segment.h"
#include "ECU_Layer/Buzzer/ecu_buzzer.h"
/* Section : Macro Declarations */
#define _XTAL_FREQ 4000000UL
/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Function Prototype */
void application_init(void);
void timer_init(void);
#endif	/* APPLICATION_H */

