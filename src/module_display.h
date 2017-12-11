#pragma once

#define USE_ADAFRUIT
//#define USE_U8G2
#define SH1106_ADDRESS 0x3C

namespace ModuleDisplay
{
    void setup();

    void draw_frame();

}