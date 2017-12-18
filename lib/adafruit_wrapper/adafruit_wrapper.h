#pragma once
#include <Arduino.h>

void adafruit_setup(uint8_t address);

uint16_t adafruit_get_width();

uint16_t adafruit_get_height();

void adafruit_get_text_size(const char* text, uint16_t* width, uint16_t* height);

void adafruit_get_text_size(const __FlashStringHelper * text, uint16_t* width, uint16_t* height);

void adafruit_begin();

void adafruit_end();

void adafruit_drawtext(uint16_t x, uint16_t y, const __FlashStringHelper * text);

void adafruit_drawline(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void adafruit_drawrect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

