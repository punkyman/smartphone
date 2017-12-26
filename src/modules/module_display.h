#pragma once
#include <Arduino.h>

#define USE_ADAFRUIT
//#define USE_U8G2
#define SH1106_ADDRESS 0x3C

namespace ModuleDisplay
{
    uint8_t getScreenWidth();

    uint8_t getScreenHeight();

    void getTextSizeChar(const char* text, uint8_t* width, uint8_t* height);

    void getTextSizeFSH(const __FlashStringHelper* text, uint8_t* width, uint8_t* height);

    void setup();

    void begin();

    void end();

    void drawTextChar(uint8_t x, uint8_t y, const char* text);

    void drawTextFSH(uint8_t x, uint8_t y, const __FlashStringHelper* text);

    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void drawCircle(uint8_t x, uint8_t y, uint8_t r);
}