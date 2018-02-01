#pragma once

namespace Menu
{
    struct Listener
    {
        virtual bool listener(int msg) = 0; // returns true if message is intercepted
    };
}
