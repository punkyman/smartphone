#pragma once
#include <Arduino.h>

 namespace Menu
 {
     struct Rect
     {
        Rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h) : x(x), y(y), w(w), h(h) {}
        uint8_t x, y, w, h;
     };
 };
