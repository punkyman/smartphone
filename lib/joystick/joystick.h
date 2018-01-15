#pragma once
#include <Arduino.h>

#define INVERT_AXIS

#define ANALOG_MAX 1024
#define ANALOG_CENTER 512

#define DEADZONE_AXIS(v) do {v = (v < 500 || v > 524) ? v : 512;} while(0)

extern uint16_t joystick_analog_X;
extern uint16_t joystick_analog_Y;
extern bool joystick_switch;

void joystick_init(uint8_t analog_x_pin, uint8_t analog_y_pin, uint8_t switch_pin);
void joystick_read_values();
