/* 
 * File:   Buzzer.h
 * Author: mahdy
 *
 * Created on August 7, 2023, 5:48 PM
 */

#include "ecu_buzzer.h"

/**
 * 
 * @param buzzer_config
 * @return  Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */

Std_ReturnType buzzer_initialization(const buzzer_t *buzzer_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == buzzer_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_init(&(buzzer_config -> buzzer_pin));
    }
    return ret;
}

/**
 * 
 * @param buzzer_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType buzzer_on(const buzzer_t *buzzer_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == buzzer_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param buzzer_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType buzzer_off(const buzzer_t *buzzer_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == buzzer_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param buzzer_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType buzzer_beeb(const buzzer_t *buzzer_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == buzzer_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_HIGH);
        __delay_ms(500);
        
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_LOW);
        __delay_ms(50);
        
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_HIGH);
        __delay_ms(500);
        
        ret = gpio_pin_write_logic(&(buzzer_config -> buzzer_pin), GPIO_LOW);
        __delay_ms(50);
    }
    return ret;
}