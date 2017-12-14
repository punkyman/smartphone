#pragma once
#include <Arduino.h>

#define USE_ADAFRUIT
//#define USE_U8G2
#define SH1106_ADDRESS 0x3C

namespace ModuleDisplay
{
    void setup();

    void begin();

    void end();

    void drawText(uint8_t x, uint8_t y, const char* text);

}