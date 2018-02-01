#pragma once
#include "listener.h"

namespace Menu
{
    namespace Channel
    {
        static const unsigned int max_listeners = 8;
        enum MESSAGES
        {
            MSG_OK,
            MSG_ERROR,
        };

        void init();

        bool Register(Listener* obj);
        bool Unregister(Listener* obj);

        void Notify(int msg);
    }
}