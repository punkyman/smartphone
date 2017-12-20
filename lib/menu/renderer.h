#pragma once
#include <Arduino.h>

namespace Menu
{

    static const uint8_t text_spacing = 1;
    static const uint8_t text_margin = 2;

struct Renderer
{
    Renderer(int screenWidth, int screenHeight) 
    : screenWidth(screenWidth), screenHeight(screenHeight) { }

    // text, width, height
    void (*getTextSizeChar)(const char *, uint8_t*, uint8_t*);
        // text, width, height
    void (*getTextSizeFSH)(const __FlashStringHelper*, uint8_t*, uint8_t*);
    // x, y, text
    void (*drawTextChar)(uint8_t, uint8_t, const char *);
    // x, y, text
    void (*drawTextFSH)(uint8_t, uint8_t, const __FlashStringHelper *);
    // x0, y0, x1, y1 
    void (*drawLine)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    void (*drawRect)(uint8_t, uint8_t, uint8_t, uint8_t);
    // x, y, w, h
    void (*fillRect)(uint8_t, uint8_t, uint8_t, uint8_t);

    uint8_t screenWidth;
    uint8_t screenHeight;
};

};