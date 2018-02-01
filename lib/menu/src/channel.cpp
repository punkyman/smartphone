#include "channel.h"
#include <Arduino.h>

namespace Menu
{
namespace Channel
{

LISTENER listeners[max_listeners];

void init()
{
    memset(listeners, 0, sizeof(LISTENER) * max_listeners);
}

bool Register(LISTENER elt)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] == nullptr)
        {
            listeners[i] = elt;
            return true;
        }
    }

    return false;
}

bool Unregister(LISTENER elt)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] == elt)
        {
            listeners[i] = nullptr;
            return true;
        }
    }

    return false;
}

void Notify(int msg)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] != nullptr)
            listeners[i](msg);
    }    
}

} // namespace Channel
} // namespace Menu
