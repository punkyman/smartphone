#pragma once
#include <Arduino.h>

namespace Menu
{
    enum FONT_SIZE
    {
        NORMAL   = 1,
        BIG      = 2,
        HUGE     = 3,
    };

    // text, is_in_progmem, width, height, font_size
    typedef void (*GETTEXTSIZE)(const char *, bool, uint8_t*, uint8_t*, uint8_t);
    // x, y, text, is_in_progmem, font_size
    typedef void (*DRAWTEXT)(uint8_t, uint8_t, const char *, bool, uint8_t);
    // x0, y0, x1, y1 
    typedef void (*DRAWLINE)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    typedef void (*DRAWRECT)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    typedef void (*FILLRECT)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, r
    typedef void (*DRAWCIRCLE)(uint8_t, uint8_t, uint8_t);
    // x, y, w, h, data(in progmem)
    typedef void (*DRAWBITMAP)(uint8_t, uint8_t, uint8_t, uint8_t, const uint8_t[]);

    static const uint8_t text_spacing = 1;
    static const uint8_t text_margin = 2;
    static const uint8_t circle_margin = 2;

struct Renderer
{
    Renderer(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight) {}

    GETTEXTSIZE getTextSize;
    DRAWTEXT drawText;
    DRAWLINE drawLine;
    DRAWRECT drawRect;
    FILLRECT fillRect;
    DRAWCIRCLE drawCircle;
    DRAWBITMAP drawBitmap;

    uint8_t screenWidth;
    uint8_t screenHeight;
};

};