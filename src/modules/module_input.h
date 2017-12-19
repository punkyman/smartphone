#pragma once

#define USE_JOYSTICK

namespace ModuleInput
{
    static const float analog_treshold = 0.5f;
    
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


