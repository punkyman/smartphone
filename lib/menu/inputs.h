#pragma once

namespace Menu
{
    typedef uint8_t Inputs; // has to be wide enough to contain the enum values
    
    enum MENU_INPUT
    {
        INPUT_PREVIOUS  = 1 << 0,
        INPUT_NEXT      = 1 << 1,
        INPUT_BACK      = 1 << 2,
        INPUT_VALIDATE  = 1 << 3,
    };
}
