#pragma once
#include <Arduino.h>

namespace ModuleDisplay
{

    uint8_t getScreenWidth();

    uint8_t getScreenHeight();

    void getTextSize(const char* text, bool progmem, uint8_t* width, uint8_t* height, uint8_t size);

    void setup();

    void begin();

    void end();

    void drawText(uint8_t x, uint8_t y, const char* text, bool progmem, uint8_t size);
    
    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

    void drawCircle(uint8_t x, uint8_t y, uint8_t r);

    // draw a bitmap of size w,h that sits in progmem
    void drawBitmap(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t data[]);

}