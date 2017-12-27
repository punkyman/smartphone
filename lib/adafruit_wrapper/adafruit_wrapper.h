#pragma once
#include <Arduino.h>

//#define USE_SH1106
#define USE_PCD8544

void adafruit_setup(uint8_t address);

uint16_t adafruit_get_width();

uint16_t adafruit_get_height();

void adafruit_setfontsize(uint8_t size);

void adafruit_get_text_size(const char* text, uint16_t* width, uint16_t* height);

void adafruit_get_text_size(const __FlashStringHelper* text, uint16_t* width, uint16_t* height);

void adafruit_begin();

void adafruit_end();

void adafruit_drawtext(uint16_t x, uint16_t y, const char* text);

void adafruit_drawtext(uint16_t x, uint16_t y, const __FlashStringHelper* text);

void adafruit_drawline(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void adafruit_drawrect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

void adafruit_fillrect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

void adafruit_drawcircle(uint16_t x, uint16_t y, uint16_t r);

void adafruit_drawbitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t data[]);