#include <hal.h>
#include "messaging.h"
#include "listener.h"

namespace Messaging
{

Listener* listeners[max_listeners];
uint8_t channels[max_listeners];


void init()
{
    memset(listeners, 0, sizeof(Listener*) * max_listeners);
    memset(channels, 0, sizeof(uint8_t) * max_listeners);
}

bool Register(Listener* obj, uint8_t channel)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] == nullptr)
        {
            listeners[i] = obj;
            channels[i] = channel;
            return true;
        }
    }

    return false;
}

bool Unregister(Listener* obj)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] == obj)
        {
            listeners[i] = nullptr;
            channels[i] = 0;
            return true;
        }
    }

    return false;
}

void Notify(uint8_t channel, int msg)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(channels[i] == channel)
            if(listeners[i] != nullptr)
                if(listeners[i]->listener(msg))
                    return;
    }    
}

} // namespace Messaging
