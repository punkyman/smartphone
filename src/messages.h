#pragma once
#include <Arduino.h>

namespace Messages
{
    static const uint8_t Channel = 1;
    enum MESSAGES
    {
        MSG_GSM_OPERATION_SUCCESS           = 1 << 0,
        MSG_GSM_OPERATION_FAILURE           = 1 << 1,
    };
}
