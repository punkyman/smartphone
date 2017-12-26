#pragma once
#include <Arduino.h>

// Getters have to be used one per one, as temporary data is used internally
const char* g_get_temperature();

const char* g_get_pressure();

uint8_t g_get_battery_level();

// boolean returns if controller is calibrated or not
bool g_get_compass_data(float* roll, float* pitch, float* yaw);
