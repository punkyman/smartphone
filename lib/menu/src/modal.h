#pragma once
#include <Arduino.h>
#include "inputs.h"
#include "channel/listener.h"

namespace Menu
{
    struct Renderer;

    struct Modal : Listener
    {
        static const int screen_margin = 4;

        Modal();

        bool update(Inputs inputs);

        void draw(Renderer* render);

        virtual bool listener(int msg);

        bool active;
    };
}

