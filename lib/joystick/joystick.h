#pragma once
#include <Arduino.h>

#define ANALOG_PIN_AXIS_X A0
#define ANALOG_PIN_AXIS_Y A1
#define DIGITAL_PIN_SWITCH 2

#define ANALOG_MAX 1024.0f

#define SCALE_AXIS(v) do {v *= 2.0f; v -=1.0f;} while(0)
#define DEADZONE_AXIS(v) do {v = (v > 0.05f || v < -0.05f) ? v : 0.0f;} while(0)

extern float joystick_analog_X;
extern float joystick_analog_Y;
extern bool joystick_switch;

void init_joystick();
void read_values();
