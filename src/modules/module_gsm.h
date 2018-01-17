#pragma once
#include <Arduino.h>

#define SIGNAL_UPDATE 10000

namespace ModuleGsm
{
    void setup();

    void update();

    bool send_sms(const char* number, const char* text);

    bool is_command_running();

    bool set_microphone_gain(uint8_t value); // 0..15

    uint8_t get_signal_level();
}
