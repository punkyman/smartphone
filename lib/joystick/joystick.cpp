#include "joystick.h"

uint8_t joystick_analog_x_pin, joystick_analog_y_pin, joystick_switch_pin;

uint16_t joystick_analog_X = 0;
uint16_t joystick_analog_Y = 0;
bool joystick_switch = false;

void joystick_init(uint8_t analog_x_pin, uint8_t analog_y_pin, uint8_t switch_pin)
{
    joystick_analog_x_pin = analog_x_pin;
    joystick_analog_y_pin = analog_y_pin;
    joystick_switch_pin = switch_pin;

#if defined(STM32_MCU_SERIES)
    pinMode(joystick_analog_x_pin, INPUT_ANALOG);
    pinMode(joystick_analog_y_pin, INPUT_ANALOG);
#endif
    pinMode(joystick_switch_pin, INPUT_PULLUP);
}

void joystick_read_values()
{
#ifndef INVERT_AXIS
    joystick_analog_X = analogRead(joystick_analog_x_pin);
    joystick_analog_Y = analogRead(joystick_analog_y_pin);
#else
    joystick_analog_X = analogRead(joystick_analog_y_pin);
    joystick_analog_Y = analogRead(joystick_analog_x_pin);
#endif
    joystick_switch = digitalRead(joystick_switch_pin) != HIGH;

#if defined(STM32_MCU_SERIES)
    joystick_analog_X = joystick_analog_X >> 2;
    joystick_analog_Y = joystick_analog_Y >> 2;
#endif

    DEADZONE_AXIS(joystick_analog_X);
    DEADZONE_AXIS(joystick_analog_Y);
}