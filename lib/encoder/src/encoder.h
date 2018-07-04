#pragma once
#include <Arduino.h>

#define USE_CLICK_ENCODER

extern volatile int8_t encoder_scrolls;
extern bool encoder_switch;

void encoder_init(uint8_t clock_pin, uint8_t data_pin, uint8_t switch_pin);
void encoder_clear_readings();
void encoder_read_values();
