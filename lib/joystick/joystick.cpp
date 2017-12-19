#include "joystick.h"

float joystick_analog_X = 0.0f;
float joystick_analog_Y = 0.0f;
bool joystick_switch = false;

void init_joystick()
{
    pinMode(DIGITAL_PIN_SWITCH, INPUT);
}

void read_values()
{
    joystick_analog_X = analogRead(ANALOG_PIN_AXIS_X) / ANALOG_MAX;
    joystick_analog_Y = analogRead(ANALOG_PIN_AXIS_Y) / ANALOG_MAX;
    joystick_switch = digitalRead(DIGITAL_PIN_SWITCH) != HIGH;

    SCALE_AXIS(joystick_analog_X);
    SCALE_AXIS(joystick_analog_Y);
    DEADZONE_AXIS(joystick_analog_X);
    DEADZONE_AXIS(joystick_analog_Y);
}