/* 
 * File:   ecu_sev_segment.c
 * Author: mahdy
 *
 * Created on August 7, 2023, 2:46 PM
 */

#include "ecu_sev_segment.h"



/**
 * 
 * @param seg_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType seven_segment_initialize(const segment_t *seg_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == seg_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        if((gpio_pin_direction_init(&(seg_config -> segment_pins[0]))) &&
           (gpio_pin_direction_init(&(seg_config -> segment_pins[1]))) &&
           (gpio_pin_direction_init(&(seg_config -> segment_pins[2]))) &&
           (gpio_pin_direction_init(&(seg_config -> segment_pins[3]))) )
        {
            /*do nothing*/           
        }
        
        else
        {
            ret = E_NOT_OK;
        }
    }
    
    return ret;
}

/**
 * 
 * @param seg_config
 * @param number
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType seven_segment_write_number(const segment_t *seg_config, uint8 number)
{
    
    Std_ReturnType ret = E_OK;
    if(NULL == seg_config ||  number > (uint8)9)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((gpio_pin_write_logic(&(seg_config -> segment_pins[0]), number & 0x01)) &&
           (gpio_pin_write_logic(&(seg_config -> segment_pins[1]), (number >> 1 )& 0x01)) &&
           (gpio_pin_write_logic(&(seg_config -> segment_pins[2]), (number >> 2 )& 0x01)) &&
           (gpio_pin_write_logic(&(seg_config -> segment_pins[3]), (number >> 3 )& 0x01)) )
        {
            /*do nothing*/
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    
    return ret;
    
}



#if SEGMENT_CONFIG==MULTIPLEXED
/**
 * 
 * @param seg_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue
 */
Std_ReturnType seven_segment_control_initialize(const pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_init(pin_config);
    }
    
    return ret;
}

/**
 * 
 * @param seg_config
 * @param pin_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has is
 */
Std_ReturnType seven_segment_control_turn_on(const segment_t *seg_config, const pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == seg_config || NULL == pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(seg_config -> segment_type == SEGMENT_COMMON_ANODE)
        {
            ret = gpio_pin_write_logic(pin_config, GPIO_HIGH);
        }
        else if(seg_config -> segment_type == SEGMENT_COMMON_CATHODE)
        {
            ret = gpio_pin_write_logic(pin_config, GPIO_LOW);
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    
    return ret;
}
/**
 * 
 * @param seg_config
 * @param pin_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has is
 */
Std_ReturnType seven_segment_control_turn_off(const segment_t *seg_config, const pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == seg_config || NULL == pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(seg_config -> segment_type == SEGMENT_COMMON_ANODE)
        {
            ret = gpio_pin_write_logic(pin_config, GPIO_LOW);
        }
        else if(seg_config -> segment_type == SEGMENT_COMMON_CATHODE)
        {
            ret = gpio_pin_write_logic(pin_config, GPIO_HIGH);
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif