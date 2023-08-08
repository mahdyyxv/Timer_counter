/* 
 * File:   application.c
 * Author: mahdy
 *
 * Created on August 1, 2023, 3:35 PM
 */

#include "application.h"
button_t up_button=
{
    .btn_obj.port       = PORTB_INDEX,
    .btn_obj.pin        = PIN0,
    .btn_obj.direction  = GPIO_INPUT,
    
    .button_connection  = BUTTON_ACTIVE_HIGH, 
    .button_state       = BUTTON_RELEASED

};

button_t down_button=
{
    .btn_obj.port       = PORTB_INDEX,
    .btn_obj.pin        = PIN1,
    .btn_obj.direction  = GPIO_INPUT,
    
    .button_connection  = BUTTON_ACTIVE_HIGH, 
    .button_state       = BUTTON_RELEASED

};

button_t set_button=
{
    .btn_obj.port       = PORTB_INDEX,
    .btn_obj.pin        = PIN2,
    .btn_obj.direction  = GPIO_INPUT,
    
    .button_connection  = BUTTON_ACTIVE_HIGH, 
    .button_state       = BUTTON_RELEASED

};


segment_t  segment_1 = 
{
    .segment_pins[0].port       = PORTC_INDEX,
    .segment_pins[0].pin        = PIN0,
    .segment_pins[0].direction  = GPIO_OUTPUT,
    .segment_pins[0].logic      = GPIO_LOW,
    
    .segment_pins[1].port       = PORTC_INDEX,
    .segment_pins[1].pin        = PIN1,
    .segment_pins[1].direction  = GPIO_OUTPUT,
    .segment_pins[1].logic      = GPIO_LOW,
    
    .segment_pins[2].port       = PORTC_INDEX,
    .segment_pins[2].pin        = PIN2,
    .segment_pins[2].direction  = GPIO_OUTPUT,
    .segment_pins[2].logic      = GPIO_LOW,
    
    .segment_pins[3].port       = PORTC_INDEX,
    .segment_pins[3].pin        = PIN3,
    .segment_pins[3].direction  = GPIO_OUTPUT,
    .segment_pins[3].logic      = GPIO_LOW,
       
    .segment_type               = SEGMENT_COMMON_ANODE
};

pin_config_t segment_1_control=
{
    .pin        = PIN0,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};
pin_config_t segment_2_control=
{
    .pin        = PIN1,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};
pin_config_t segment_3_control=
{
    .pin        = PIN2,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};
pin_config_t segment_4_control=
{
    .pin        = PIN3,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};

pin_config_t segment_5_control=
{
    .pin        = PIN4,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};

pin_config_t segment_6_control=
{
    .pin        = PIN5,
    .port       = PORTD_INDEX,
    .logic      = GPIO_LOW,
    .direction  = GPIO_OUTPUT
};

buzzer_t buzzer={
    .buzzer_pin.port        = PORTA_INDEX,
    .buzzer_pin.pin         = PIN0,
    .buzzer_pin.logic       = GPIO_LOW,
    .buzzer_pin.direction   = GPIO_OUTPUT
};

typedef struct
{
    uint8 flag : 1;
}flag_t;

flag_t loop_flag;

Std_ReturnType ret = E_NOT_OK;
button_state_t up_button_state      = BUTTON_RELEASED, 
               down_button_state    = BUTTON_RELEASED, 
               set_button_state     = BUTTON_RELEASED;
sint8 hours = 0, minutes = 0, seconds = 0, counter = 0;
uint32 total_secondes;
sint8 var = 0;
int main(void) {
    application_init();
    total_secondes = ( (hours * 60 * 60) + (minutes * 60) + (seconds) );
    while(1)
    {
        if( (total_secondes == 0) && (loop_flag.flag == 1) )
        {
            button_read_logic(&set_button, &set_button_state);
            button_read_logic(&up_button, &up_button_state);
            
            buzzer_on(&buzzer);
            if(up_button_state == BUTTON_PRESSED) {
                loop_flag.flag = 0;
                buzzer_off(&buzzer);
            }
            if(set_button_state == BUTTON_PRESSED)
            {
                buzzer_off(&buzzer);
                __delay_ms(5);
                timer_init();
                total_secondes = ( (hours * 60 * 60) + (minutes * 60) + (seconds) ); 
                set_button_state = BUTTON_RELEASED;
            }
            
        }
        
        else if (total_secondes != 0){
            total_secondes--;
            for(counter = 0; counter <= 50; counter++)
            {
                seven_segment_write_number(&segment_1, (uint8)(seconds % 10));
                seven_segment_control_turn_on(&segment_1, &segment_6_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_6_control);
                __delay_us(100);

                seven_segment_write_number(&segment_1, (uint8)(seconds / 10));
                seven_segment_control_turn_on(&segment_1, &segment_5_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_5_control);
                __delay_us(100);
                
                
                seven_segment_write_number(&segment_1, (uint8)(minutes % 10));
                seven_segment_control_turn_on(&segment_1, &segment_4_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_4_control);
                __delay_us(100);

                seven_segment_write_number(&segment_1, (uint8)(minutes / 10));
                seven_segment_control_turn_on(&segment_1, &segment_3_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_3_control);
                __delay_us(100);
                
                seven_segment_write_number(&segment_1, (uint8)(hours % 10));
                seven_segment_control_turn_on(&segment_1, &segment_2_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_2_control);
                __delay_us(100);

                seven_segment_write_number(&segment_1, (uint8)(hours / 10));
                seven_segment_control_turn_on(&segment_1, &segment_1_control);
                __delay_us(100);
                seven_segment_control_turn_off(&segment_1, &segment_1_control);
                __delay_us(100);
            }
            
            
            seconds--;
            if(seconds <= 0)
            {
                
                if((minutes == 0) &&(hours == 0))
                {
                    seconds = 0;
                    total_secondes = 0;
                }
                else
                {
                    seconds = 59;
                }
                
                minutes--;
                if(minutes < 0){
                    minutes = 0;
                    hours = (hours <= 0)? 0 : hours--;
                }
            }
            
        }
        else {
            /*do nothing*/
        }
    }
    return (EXIT_SUCCESS);
}

void application_init(void)
{
    
    seven_segment_initialize(&segment_1);
    seven_segment_control_initialize(&segment_1_control);
    seven_segment_control_initialize(&segment_2_control);
    seven_segment_control_initialize(&segment_3_control);
    seven_segment_control_initialize(&segment_4_control);
    seven_segment_control_initialize(&segment_5_control);
    seven_segment_control_initialize(&segment_6_control);
    
    button_initialization(&up_button);
    button_initialization(&down_button);
    button_initialization(&set_button);
    buzzer_initialization(&buzzer);
    timer_init();
}

void timer_init(void)
{
    loop_flag.flag = 0;
    while(0 == loop_flag.flag)
    {
        seconds = 0;
        set_button_state     = BUTTON_RELEASED;
        while( (0 == seconds) && (BUTTON_RELEASED == set_button_state) )
        { 
            seven_segment_write_number(&segment_1, (uint8)(var % 10));
            seven_segment_control_turn_on(&segment_1, &segment_6_control);
            __delay_us(1);
            seven_segment_control_turn_off(&segment_1, &segment_6_control);
            __delay_us(1);
            
            seven_segment_write_number(&segment_1, (uint8)(var / 10));
            seven_segment_control_turn_on(&segment_1, &segment_5_control);
            __delay_us(1);
            seven_segment_control_turn_off(&segment_1, &segment_5_control);
            __delay_us(1);
            button_read_logic(&set_button, &set_button_state);
            button_read_logic(&up_button, &up_button_state);
            button_read_logic(&down_button, &down_button_state);
            if((BUTTON_PRESSED == up_button_state)){
                var++;
                if(var>=59) var = 0;
                up_button_state = BUTTON_RELEASED;
            }
            if((BUTTON_PRESSED == down_button_state)){
                var--;
                if(var<=0) var = 0;
                down_button_state = BUTTON_RELEASED;
            }
            //__delay_ms(10);
        }
        set_button_state     = BUTTON_RELEASED;
        seconds = var;
        var = 0;
        while( (0 == minutes) && (BUTTON_RELEASED == set_button_state) )
        { 
            seven_segment_write_number(&segment_1, (uint8)(var % 10));
            seven_segment_control_turn_on(&segment_1, &segment_4_control);
            __delay_ms(1);
            seven_segment_control_turn_off(&segment_1, &segment_4_control);
            __delay_ms(1);
            
            seven_segment_write_number(&segment_1, (uint8)(var / 10));
            seven_segment_control_turn_on(&segment_1, &segment_3_control);
            __delay_ms(1);
            seven_segment_control_turn_off(&segment_1, &segment_3_control);
            __delay_ms(1);
            button_read_logic(&set_button, &set_button_state);
            button_read_logic(&up_button, &up_button_state);
            button_read_logic(&down_button, &down_button_state);
            if((BUTTON_PRESSED == up_button_state)){
                var++;
                if(var>=59) var = 0;
                up_button_state = BUTTON_RELEASED;
            }
            if((BUTTON_PRESSED == down_button_state)){
                var--;
                if(var<=0) var = 0;
                down_button_state = BUTTON_RELEASED;
            }
           // __delay_ms(10);
        }
        
        set_button_state     = BUTTON_RELEASED;
        minutes = var;
        var = 0;
        while( (0 == hours) && (BUTTON_RELEASED == set_button_state) )
        { 
            seven_segment_write_number(&segment_1, (uint8)(var % 10));
            seven_segment_control_turn_on(&segment_1, &segment_2_control);
            __delay_ms(1);
            seven_segment_control_turn_off(&segment_1, &segment_2_control);
            __delay_ms(1);
            
            seven_segment_write_number(&segment_1, (uint8)(var / 10));
            seven_segment_control_turn_on(&segment_1, &segment_1_control);
            __delay_ms(1);
            seven_segment_control_turn_off(&segment_1, &segment_1_control);
            __delay_ms(1);
            button_read_logic(&set_button, &set_button_state);
            button_read_logic(&up_button, &up_button_state);
            button_read_logic(&down_button, &down_button_state);
            if((BUTTON_PRESSED == up_button_state)){
                var++;
                if(var>=23) var = 0;
                up_button_state = BUTTON_RELEASED;
            }
            if((BUTTON_PRESSED == down_button_state)){
                var--;
                if(var<=0) var = 0;
                down_button_state = BUTTON_RELEASED;
            }
        }
        set_button_state     = BUTTON_RELEASED;
        hours = var;
        loop_flag.flag = 1;
    }
    
}




////
////led_t led1 = 
////{
////    .port = PORTA_INDEX,
////    .pin = PIN0,
////    .status = LED_ON
////};
////
////led_t led2 = 
////{
////    .port = PORTA_INDEX,
////    .pin = PIN1,
////    .status = LED_ON
////};
////
////led_t led3 = 
////{
////    .port = PORTA_INDEX,
////    .pin = PIN2,
////    .status = LED_ON
////};
////
////button_t btn_high =
////{
////    .btn_obj.port = PORTC_INDEX,
////    .btn_obj.pin = PIN0,
////    .btn_obj.direction = GPIO_INPUT,
////    .btn_obj.logic = GPIO_HIGH,
////    .button_state = BUTTON_PRESSED,
////    .button_connection = BUTTON_ACTIVE_HIGH  
////};
////
////button_t btn_low =
////{
////    .btn_obj.port = PORTC_INDEX,
////    .btn_obj.pin = PIN1,
////    .btn_obj.direction = GPIO_INPUT,
////    .btn_obj.logic = GPIO_HIGH,
////    .button_state = BUTTON_PRESSED,
////    .button_connection = BUTTON_ACTIVE_LOW 
////};
////relay_t relay_1 = {
////    .port   = PORTB_INDEX,
////    .pin    = PIN0,
////    .status = RELAY_STATE_OFF
////};
//
////
////dc_motor_t dc_motor_1 = {
////    .motor[0].pin    = PIN0,
////    .motor[0].port   = PORTC_INDEX,
////    .motor[0].logic = DC_MOTOR_OFF_STATE,
////    .motor[0].direction = GPIO_OUTPUT,
////    
////    .motor[1].pin    = PIN1,
////    .motor[1].port   = PORTC_INDEX,
////    .motor[1].logic = DC_MOTOR_OFF_STATE,
////    .motor[1].direction = GPIO_OUTPUT,
////    
////};
////
////dc_motor_t dc_motor_2 = {
////    .motor[0].pin    = PIN4,
////    .motor[0].port   = PORTC_INDEX,
////    .motor[0].logic = DC_MOTOR_OFF_STATE,
////    .motor[0].direction = GPIO_OUTPUT,
////    
////    .motor[1].pin    = PIN5,
////    .motor[1].port   = PORTC_INDEX,
////    .motor[1].logic = DC_MOTOR_OFF_STATE,
////    .motor[1].direction = GPIO_OUTPUT,
////    
////};
//
//segment_t  segment_1 = 
//{
//    .segment_pins[0].port       = PORTC_INDEX,
//    .segment_pins[0].pin        = PIN0,
//    .segment_pins[0].direction  = GPIO_OUTPUT,
//    .segment_pins[0].logic      = GPIO_LOW,
//    
//    .segment_pins[1].port       = PORTC_INDEX,
//    .segment_pins[1].pin        = PIN1,
//    .segment_pins[1].direction  = GPIO_OUTPUT,
//    .segment_pins[1].logic      = GPIO_LOW,
//    
//    .segment_pins[2].port       = PORTC_INDEX,
//    .segment_pins[2].pin        = PIN2,
//    .segment_pins[2].direction  = GPIO_OUTPUT,
//    .segment_pins[2].logic      = GPIO_LOW,
//    
//    .segment_pins[3].port       = PORTC_INDEX,
//    .segment_pins[3].pin        = PIN3,
//    .segment_pins[3].direction  = GPIO_OUTPUT,
//    .segment_pins[3].logic      = GPIO_LOW,
//    
//    .segment_type               = SEGMENT_COMMON_ANODE
//};
//Std_ReturnType ret = E_NOT_OK;
//button_state_t button_high_value, button_low_value;


/**
 void application_init(void)
{
//   led_initialization(&led1); 
//   led_initialization(&led2); 
//   led_initialization(&led3); 
//   button_initialization(&btn_high);
//   button_initialization(&btn_low);
//   relay_initialization(&relay_1);
//    ret = seven_segment_initialize(&segment_1);
}
 */

//        button_read_logic(&btn_high, &button_high_value);
//        button_read_logic(&btn_low, &button_low_value);
//        
//        if(button_high_value == BUTTON_PRESSED)
//        {
//            led_toggle(&led1);
//            __delay_ms(100);
//        }
//        else{/*do nothing*/}
//        
//        if(button_low_value == BUTTON_PRESSED)
//        {
//          led_toggle(&led2);
//            __delay_ms(100);
//        }
//        else{/*do nothing*/}
//        relay_on(&relay_1);
//        __delay_ms(1020);
//        relay_off(&relay_1);
//        __delay_ms(1000);
//        ret = dc_motor_move_left(&dc_motor_1);
//        ret = dc_motor_move_left(&dc_motor_2);
//        __delay_ms(3000);
//        
//        ret = dc_motor_move_right(&dc_motor_1);
//        ret = dc_motor_move_right(&dc_motor_2);
//        __delay_ms(3000);
//        
//        ret = dc_motor_move_stop(&dc_motor_1);
//        ret = dc_motor_move_stop(&dc_motor_2);
//        __delay_ms(3000);
//        
//        ret = dc_motor_move_right(&dc_motor_1);
//        ret = dc_motor_move_left(&dc_motor_2);
//        __delay_ms(3000);
//        
//        ret = dc_motor_move_stop(&dc_motor_1);
//        ret = dc_motor_move_stop(&dc_motor_2);
//        __delay_ms(3000);
//        
//        ret = dc_motor_move_left(&dc_motor_1);
//        ret = dc_motor_move_right(&dc_motor_2);
//        __delay_ms(3000);