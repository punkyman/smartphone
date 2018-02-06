#pragma once
#include <Arduino.h>

namespace Menu
{
    namespace Channel
    {
        typedef uint8_t Message; // has to be wide enough to contain the enum values    
        enum MESSAGES
        {
            MSG_OPERATION_FAILURE           = 1 << 0,
            MSG_OPERATION_IN_PROGRESS       = 1 << 1,
            MSG_OPERATION_SUCCESS           = 1 << 2,
        };
    }
}
