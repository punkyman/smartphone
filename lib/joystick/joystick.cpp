#include "joystick.h"

uint16_t joystick_analog_X = 0;
uint16_t joystick_analog_Y = 0;
bool joystick_switch = false;

void joystick_init()
{
    pinMode(DIGITAL_PIN_SWITCH, INPUT_PULLUP);
}

void joystick_read_values()
{
#ifndef INVERT_AXIS
    joystick_analog_X = analogRead(ANALOG_PIN_AXIS_X);
    joystick_analog_Y = analogRead(ANALOG_PIN_AXIS_Y);
#else
    joystick_analog_X = analogRead(ANALOG_PIN_AXIS_Y);
    joystick_analog_Y = analogRead(ANALOG_PIN_AXIS_X);
#endif
    joystick_switch = digitalRead(DIGITAL_PIN_SWITCH) != HIGH;

    DEADZONE_AXIS(joystick_analog_X);
    DEADZONE_AXIS(joystick_analog_Y);
}