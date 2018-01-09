#pragma once
#include <Arduino.h>

#define USE_JOYSTICK

namespace ModuleInput
{
    static const uint16_t analog_treshold = 256;
    
    struct Inputs
    {
        Inputs();

        bool up, down, left, right, validate;
        bool pressed_up, pressed_down, pressed_left, pressed_right, pressed_validate;
        bool released_up, released_down, released_left, released_right, released_validate;
    };

    const Inputs* getInputs();

    void setup();

    void update();   
};


