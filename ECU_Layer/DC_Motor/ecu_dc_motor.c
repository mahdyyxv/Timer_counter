/* 
 * File:   ecu_dc_motor.c
 * Author: mahdy
 *
 * Created on August 6, 2023, 1:25 PM
 */

#include "ecu_dc_motor.h"


/**
 * 
 * @param motor_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType  dc_motor_initialization(const dc_motor_t *motor_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == motor_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        
        
        if ( (gpio_pin_direction_init(&(motor_config ->motor[DC_MOTOR_PIN1]))) && (gpio_pin_direction_init(&(motor_config ->motor[DC_MOTOR_PIN2]))) )
        {
            /*do noting*/
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * 
 * @param motor_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType  dc_motor_move_left(const dc_motor_t *motor_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == motor_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if ( (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN1]), GPIO_HIGH)) && (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN2]), GPIO_LOW)) )
        {
            /*do noting*/
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * 
 * @param motor_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType  dc_motor_move_right(const dc_motor_t *motor_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == motor_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if ( (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN2]), GPIO_HIGH)) && (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN1]), GPIO_LOW)) )
        {
            /*do noting*/
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * 
 * @param motor_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
Std_ReturnType  dc_motor_move_stop(const dc_motor_t *motor_config)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == motor_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if ( (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN1]), GPIO_LOW)) && (gpio_pin_write_logic(&(motor_config ->motor[DC_MOTOR_PIN2]), GPIO_LOW)) )
        {
            /*do noting*/
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}