#pragma once
#include <Arduino.h>

namespace Globals
{
    extern int16_t g_temperature;
    extern int32_t g_pressure;
    extern uint8_t g_battery_level;
}

// Getters have to be used one per one, as temporary data is used internally
const char* g_get_temperature();
void g_set_temperature(int16_t value);

const char* g_get_pressure();
void g_set_pressure(int32_t value);

uint8_t g_get_battery_level();
void g_set_battery_level(uint8_t value);
