#pragma once
#include <Arduino.h>
#include "inputs.h"
#include "channel/listener.h"

namespace Menu
{
    struct Renderer;

    struct Modal : Channel::Listener
    {
        static const int screen_margin = 4;

        Modal();

        bool update(Inputs inputs);

        void draw(Renderer* render);

        virtual bool listener(Channel::Message msg);

        bool active;
    };
}

