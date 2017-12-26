#pragma once
#include <Arduino.h>

 namespace Menu
 {
     struct Rect
     {
        // x0,y0 upper left corner; x1,y1 lower right corner 
        Rect(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
        uint8_t x0, y0, x1, y1;
     };
 };
