#include "messaging.h"
#include "listener.h"

namespace Messaging
{

Listener* listeners[max_listeners];

void init()
{
    memset(listeners, 0, sizeof(Listener*) * max_listeners);
}

bool Register(Listener* obj)
{
    for(unsigned int i = 0; i < max_listeners; ++i)
    {
        if(listeners[i] == nullptr)
        {
            listeners[i] = obj;
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
            if(listeners[i]->listener(msg))
                return;
    }    
}

} // namespace Messaging
