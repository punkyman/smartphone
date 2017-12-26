#pragma once
#include <Arduino.h>

namespace Menu
{
    // text, width, height
    typedef void (*GETTEXTSIZECHAR)(const char *, uint8_t*, uint8_t*);
    // text, width, height
    typedef void (*GETTEXTSIZEFSH)(const __FlashStringHelper *, uint8_t*, uint8_t*);
    // x, y, text
    typedef void (*DRAWTEXTCHAR)(uint8_t, uint8_t, const char *);
    // x, y, text
    typedef void (*DRAWTEXTFSH)(uint8_t, uint8_t, const __FlashStringHelper *);
    // x0, y0, x1, y1 
    typedef void (*DRAWLINE)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    typedef void (*DRAWRECT)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    typedef void (*FILLRECT)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, r
    typedef void (*DRAWCIRCLE)(uint8_t, uint8_t, uint8_t);

    static const uint8_t text_spacing = 1;
    static const uint8_t text_margin = 2;

struct Renderer
{
    Renderer(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight) {}

    GETTEXTSIZECHAR getTextSizeChar;
    GETTEXTSIZEFSH getTextSizeFSH;
    DRAWTEXTCHAR drawTextChar;
    DRAWTEXTFSH drawTextFSH;
    DRAWLINE drawLine;
    DRAWRECT drawRect;
    FILLRECT fillRect;
    DRAWCIRCLE drawCircle;

    uint8_t screenWidth;
    uint8_t screenHeight;
};

};