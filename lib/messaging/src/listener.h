#pragma once
#include <Arduino.h>

namespace Messaging
{
    struct Listener
    {
        virtual bool listener(uint8_t msg) = 0; // returns true if message is intercepted
    };
}
