#pragma once
#include <Arduino.h>

namespace Menu
{
    namespace Messages
    {
        static const uint8_t Channel = 2;
        enum MESSAGES
        {
            MSG_OPERATION_FAILURE           = 1 << 0,
            MSG_OPERATION_SUCCESS           = 1 << 1,

            MSG_MODAL_SHOW_FAILURE          = 1 << 2,
            MSG_MODAL_SHOW_IN_PROGRESS      = 1 << 3,
            MSG_MODAL_SHOW_SUCCESS          = 1 << 4,
        };
    }
}
