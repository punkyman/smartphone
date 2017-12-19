#pragma once
#include <Arduino.h>

#define USE_ADAFRUIT
//#define USE_U8G2
#define SH1106_ADDRESS 0x3C

namespace ModuleDisplay
{
    uint8_t getScreenWidth();

    uint8_t getScreenHeight();

    void getTextSize(const char* text, uint8_t* width, uint8_t* height);

    void setup();

    void begin();

    void end();

    void drawText(uint8_t x, uint8_t y, const char* text);

    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    void drawRect(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
}