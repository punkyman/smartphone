#pragma once
#include <Arduino.h>

namespace Menu
{

struct Renderer
{
    Renderer(int screenWidth, int screenHeight) 
    : screenWidth(screenWidth), screenHeight(screenHeight) { }
    void (*drawText)(uint8_t, uint8_t, const char*);

    int screenWidth;
    int screenHeight;
};

};