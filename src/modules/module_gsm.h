#pragma once
#include <Arduino.h>

namespace ModuleGsm
{
    void setup();

    void update();

    uint8_t get_signal_level();
}
