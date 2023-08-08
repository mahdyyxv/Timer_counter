
/* 
 * File:   ecu_led.c
 * Author: mahdy
 *
 * Created on August 2, 2023, 3:07 PM
 */

#include "ecu_led.h"

/**
 * 
 * @param _led_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */

Std_ReturnType led_initialization(const led_t * _led_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {
          .port = _led_config -> port,
          .pin = _led_config -> pin,
          .direction = GPIO_OUTPUT,
          .logic = _led_config -> status
        };
        ret = gpio_pin_direction_init(&pin_obj);
    }
    
    return ret; 
}

/**
 * 
 * @param _led_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType led_on(const led_t * _led_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {
          .port = _led_config -> port,
          .pin = _led_config -> pin,
          .direction = GPIO_OUTPUT,
          .logic = _led_config -> status
        };
        ret = gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param _led_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType led_off(const led_t * _led_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == _led_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {
          .port = _led_config -> port,
          .pin = _led_config -> pin,
          .direction = GPIO_OUTPUT,
          .logic = _led_config -> status
        };
        ret = gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    
    return ret;
}

/**
 * 
 * @param _led_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType led_toggle(const led_t * _led_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == _led_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {
          .port = _led_config -> port,
          .pin = _led_config -> pin,
          .direction = GPIO_OUTPUT,
          .logic = _led_config -> status
        };
        ret = gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}