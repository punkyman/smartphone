#pragma once

namespace Messaging
{
    struct Listener;

    static const unsigned int max_listeners = 8;

    void init();

    bool Register(Listener* obj);
    bool Unregister(Listener* obj);

    void Notify(int msg);
}
