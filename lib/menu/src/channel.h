#pragma once

namespace Menu
{
    namespace Channel
    {
        typedef bool (*LISTENER)(int);
        static const unsigned int max_listeners = 8;
        enum MESSAGES
        {
            MSG_OK,
            MSG_ERROR,
        };

        void init();

        bool Register(LISTENER elt);
        bool Unregister(LISTENER elt);

        void Notify(int msg);
    }
}