#pragma once
#include <Arduino.h>

namespace ModuleGsm
{
    void setup();

    void update();

    bool is_command_running();

    uint8_t get_signal_level();
}
