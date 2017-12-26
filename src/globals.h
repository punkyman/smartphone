#pragma once
#include <Arduino.h>

// Getters have to be used one per one, as temporary data is used internally
const char* g_get_temperature();

const char* g_get_pressure();

uint8_t g_get_battery_level();
