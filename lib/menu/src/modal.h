#pragma once
#include <Arduino.h>
#include "inputs.h"
#include <listener.h>

namespace Menu
{
    struct Renderer;

    struct Modal : Messaging::Listener
    {

        enum Style
        {
            STYLE_SUCCESS        = 1 << 0,
            STYLE_IN_PROGRESS    = 1 << 1,
            STYLE_FAILURE        = 1 << 2,
        };

        static const int screen_margin = 4;
        static const int box_margin = 2;

        Modal();

        bool update(const Inputs& inputs);

        void draw(Renderer* render);

        virtual bool listener(uint8_t msg);

        bool active;
        Style style;
    };
}

