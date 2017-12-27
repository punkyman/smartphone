#pragma once
#include <Arduino.h>

#define USE_ADAFRUIT
//#define USE_U8G2
#define SH1106_ADDRESS 0x3C

namespace ModuleDisplay
{
    // has to be synced with renderer.h
    enum FONT_SIZE
    {
        NORMAL   = 1,
        BIG      = 2,
        HUGE     = 4,
    };

    uint8_t getScreenWidth();

    uint8_t getScreenHeight();

    void getTextSizeChar(const char* text, uint8_t* width, uint8_t* height, FONT_SIZE size);

    void getTextSizeFSH(const __FlashStringHelper* text, uint8_t* width, uint8_t* height, FONT_SIZE size);

    void setup();

    void begin();

    void end();

    void drawTextChar(uint8_t x, uint8_t y, const char* text, FONT_SIZE size);

    void drawTextFSH(uint8_t x, uint8_t y, const __FlashStringHelper* text, FONT_SIZE size);

    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void drawCircle(uint8_t x, uint8_t y, uint8_t r);

    // draw a bitmap of size w,h that sits in progmem
    void drawBitmap(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t data[]);

}