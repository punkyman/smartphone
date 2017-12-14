#pragma once
#include <Arduino.h>

namespace Menu
{

struct Renderer
{
    Renderer(int screenWidth, int screenHeight) 
    : screenWidth(screenWidth), screenHeight(screenHeight) { }

    void (*getTextSize)(const char*, uint8_t*, uint8_t*);
    void (*drawText)(uint8_t, uint8_t, const char*);
    void (*drawLine)(uint8_t, uint8_t, uint8_t, uint8_t);
    void (*drawRect)(uint8_t, uint8_t, uint8_t, uint8_t);

    uint8_t screenWidth;
    uint8_t screenHeight;
};

};