#pragma once
#include <Arduino.h>

void adafruit_setup(uint8_t address);

void adafruit_begin();

void adafruit_end();

void adafruit_drawtext(uint16_t x, uint16_t y, const char* text);

