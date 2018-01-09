#pragma once
#include <Arduino.h>

#define INVERT_AXIS

#define ANALOG_PIN_AXIS_X A0
#define ANALOG_PIN_AXIS_Y A1
#define DIGITAL_PIN_SWITCH 2

#define ANALOG_MAX 1024
#define ANALOG_CENTER 512

#define DEADZONE_AXIS(v) do {v = (v < 500 || v > 524) ? v : 512;} while(0)

extern uint16_t joystick_analog_X;
extern uint16_t joystick_analog_Y;
extern bool joystick_switch;

void joystick_init();
void joystick_read_values();
