#pragma once
#include <Arduino.h>
#include "inputs.h"
#include <listener.h>

namespace Menu
{
    struct Renderer;

    struct Modal : Messaging::Listener
    {
        static const int screen_margin = 4;

        Modal();

        bool update(Inputs inputs);

        void draw(Renderer* render);

        virtual bool listener(uint8_t msg);

        bool active;
    };
}

