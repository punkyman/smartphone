#pragma once
#include <Arduino.h>

namespace Globals
{
    extern int16_t g_temperature;
}

float g_get_temperature();
void g_set_temperature(int16_t value);
