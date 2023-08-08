/* 
 * File:   ecu_button.c
 * Author: mahdy
 *
 * Created on August 5, 2023, 3:23 PM
 */

#include "ecu_button.h"

/**
 * 
 * @param btn
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType  button_initialization(const button_t *btn)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == btn)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_init(&(btn->btn_obj));
    }
    
    return ret;
}

/**
 * 
 * @param btn
 * @param state
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType  button_read_logic(const button_t *btn, button_state_t *state)
{
    Std_ReturnType ret = E_OK;
    logic_t Pin_Logic_Status = GPIO_LOW;
    *state = BUTTON_RELEASED;
    if(NULL == btn || NULL == state)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_read_logic(&(btn->btn_obj), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(GPIO_HIGH == Pin_Logic_Status){
                
                __delay_ms(10);
                gpio_pin_read_logic(&(btn->btn_obj), &Pin_Logic_Status);
                if(GPIO_HIGH == Pin_Logic_Status)
                {
                    *state = BUTTON_PRESSED;
                    while(GPIO_HIGH == Pin_Logic_Status)
                    {
                        gpio_pin_read_logic(&(btn->btn_obj), &Pin_Logic_Status);
                        __delay_ms(10);
                    }
                }
                
            }
            else {
             /*do nothing*/   
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(GPIO_LOW == Pin_Logic_Status){
                __delay_ms(10);
                gpio_pin_read_logic(&(btn->btn_obj), &Pin_Logic_Status);
                if(GPIO_LOW == Pin_Logic_Status)
                {
                    *state = BUTTON_PRESSED;
                    while(GPIO_LOW == Pin_Logic_Status)
                    {
                        gpio_pin_read_logic(&(btn->btn_obj), &Pin_Logic_Status);
                        __delay_ms(10);
                    }
                }
            }
            else{
                /*do nothing*/
            }
        }
        else { /* Nothing */ }
    }
    
    return ret;
}