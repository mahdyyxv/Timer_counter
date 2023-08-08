/* 
 * File:   hal_gpio.c
 * Author: mahdy
 *
 * Created on August 1, 2023, 4:25 PM
 */

#include "hal_gpio.h"
/* Reference to Data Direction Control Register*/
volatile uint8 * tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE };
/* Reference to Data Latch Register*/
volatile uint8 * lat_registers[]  = {&LATA, &LATB, &LATC, &LATD, &LATE };
/* Reference to Port Status Register*/
volatile uint8 * port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE };

/**
 * 
 * @param _pin_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_init(const pin_config_t * _pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config -> port > PORT_MAX_NUM - 1 || _pin_config -> pin > PIN_MAX_NUM - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(_pin_config -> direction)
        {
            case GPIO_OUTPUT:
                CLEAR_BIT(*tris_registers[_pin_config -> port], _pin_config -> pin);
                ret = gpio_pin_write_logic(_pin_config, _pin_config -> logic);
                break;
            case GPIO_INPUT:
                SET_BIT(*tris_registers[_pin_config -> port], _pin_config -> pin);
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param dic_status
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t * _pin_config, direction_t *dic_status)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == dic_status || _pin_config -> port > PORT_MAX_NUM - 1 || _pin_config -> pin > PIN_MAX_NUM - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dic_status = READ_BIT(*lat_registers[_pin_config -> port], _pin_config -> pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param _logic
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t * _pin_config, logic_t _logic)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config -> port > PORT_MAX_NUM - 1 || _pin_config -> pin > PIN_MAX_NUM - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(_logic)
        {
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[_pin_config -> port], _pin_config -> pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_config -> port], _pin_config -> pin);
                break;
            default :ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param _logic
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t * _pin_config, logic_t *_logic)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config -> port > PORT_MAX_NUM - 1 || _pin_config -> pin > PIN_MAX_NUM - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *_logic = READ_BIT(*port_registers[_pin_config -> port], _pin_config -> pin);         
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t * _pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config -> port > PORT_MAX_NUM - 1 || _pin_config -> pin > PIN_MAX_NUM - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*lat_registers[_pin_config -> port], _pin_config -> pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param statue
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_init(port_index_t port, uint8 status)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUM -1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *tris_registers[port] = status;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param status
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *status)
{
    Std_ReturnType ret = E_OK;
    if(NULL == status || port > PORT_MAX_NUM -1)
    { 
        ret = E_NOT_OK;
    }
    else
    {
        *status = *tris_registers[port]; 
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUM -1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_registers[port] = logic;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
    Std_ReturnType ret = E_OK;
    if(NULL == logic || port > PORT_MAX_NUM -1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *lat_registers[port]; 
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return Status of the function
 *          (E_OK)     : the function done successfully
 *          (E_NOT_OK) : the function has issue 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUM -1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_registers[port] ^= PORT_MASK;
    }
    return ret;
}
#endif
 