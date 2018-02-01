#pragma once
#include <Arduino.h>

namespace Menu
{
    namespace Channel
    {
        typedef uint8_t Message; // has to be wide enough to contain the enum values    
        enum MESSAGES
        {
            MSG_MODAL_DISPLAY_OK           = 1 << 0,
            MSG_MODAL_DISPLAY_FAILURE      = 1 << 1,
        };
    }
}
