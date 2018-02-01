#pragma once
#include "messages.h"

namespace Menu
{
    namespace Channel
    {
        struct Listener
        {
            virtual bool listener(Message msg) = 0; // returns true if message is intercepted
        };
    }
}
