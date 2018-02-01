#pragma once
#include <Arduino.h>
#include "inputs.h"

namespace Menu
{
    struct Renderer;

    struct Modal
    {
        static const int screen_margin = 4;

        Modal();

        bool update(Inputs inputs);

        void draw(Renderer* render);

        bool active;
    };
}

