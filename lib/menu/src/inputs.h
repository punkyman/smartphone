#pragma once

namespace Menu
{
    struct Inputs
    {
        Inputs() : Navigation(0), Scroll(0) {}

        uint8_t Navigation;
        int8_t Scroll;
    };   

    enum MENU_INPUT
    {
        INPUT_BACK      = 1 << 0,
        INPUT_FORWARD   = 1 << 1,
        INPUT_VALIDATE  = 1 << 2,
    };
}
