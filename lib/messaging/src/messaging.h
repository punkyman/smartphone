#pragma once
#include <Arduino.h>

namespace Messaging
{
    struct Listener;

    static const unsigned int max_listeners = 8;

    void init();

    bool Register(Listener* obj, uint8_t channel);
    bool Unregister(Listener* obj);

    void Notify(uint8_t channel, int msg);
}
