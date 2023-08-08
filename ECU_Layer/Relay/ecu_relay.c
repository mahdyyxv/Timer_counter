/* 
 * File:   ecu_relay.c
 * Author: mahdy
 *
 * Created on August 6, 2023, 10:36 AM
 */
#include "ecu_relay.h"

/**
 * 
 * @param relay_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_initialization(const relay_t *relay_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t relay ={
          .port      = relay_config->port,
          .pin       = relay_config->pin,
          .direction = GPIO_OUTPUT,
          .logic     = relay_config->status
        };
        ret = gpio_pin_direction_init(&relay);
    }
    return ret;
}

/**
 * 
 * @param relay_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_on(const relay_t *relay_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t relay ={
          .port      = relay_config->port,
          .pin       = relay_config->pin,
          .direction = GPIO_OUTPUT,
          .logic     = ((relay_config->status) == RELAY_STATE_ON )? GPIO_HIGH : GPIO_LOW
        };
        ret = gpio_pin_write_logic(&relay, GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param relay_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_off(const relay_t *relay_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t relay ={
          .port      = relay_config->port,
          .pin       = relay_config->pin,
          .direction = GPIO_OUTPUT,
          .logic     = ((relay_config->status) == RELAY_STATE_ON )? GPIO_HIGH : GPIO_LOW
        };
        ret = gpio_pin_write_logic(&relay, GPIO_LOW);
    }
    return ret;
}

