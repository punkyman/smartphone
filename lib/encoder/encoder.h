#pragma once
#include <Arduino.h>

#define ENCODER_DIGITAL_CLOCK 2 // needs to be on an interrupt compatible pin
#define ENCODER_DIGITAL_DATA 4
#define ENCODER_DIGITAL_SWITCH 5

extern volatile int8_t encoder_scrolls;
extern bool encoder_switch;

void encoder_init();
void encoder_clear_readings();
void encoder_read_values();
