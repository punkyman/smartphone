#pragma once
#include <Arduino.h>

namespace Menu
{
    namespace Messages
    {
        static const uint8_t Channel = 1;
        enum MESSAGES
        {
            MSG_OPERATION_FAILURE           = 1 << 0,
            MSG_OPERATION_IN_PROGRESS       = 1 << 1,
            MSG_OPERATION_SUCCESS           = 1 << 2,
        };
    }
}
