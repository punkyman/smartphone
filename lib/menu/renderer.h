#pragma once
#include <Arduino.h>

namespace Menu
{

struct Renderer
{
    void (*drawText)(uint8_t, uint8_t, const char*);
};

};