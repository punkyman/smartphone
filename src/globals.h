#pragma once
#include <Arduino.h>

// Getters have to be used one per one, as temporary data is used internally
const char* g_get_temperature();

const char* g_get_pressure();

uint8_t g_get_battery_level();

// boolean returns if controller is calibrated or not
bool g_get_compass_data(float* roll, float* pitch /*, float* yaw*/);

// returns clock under format HH:MM
const char* g_get_clock();

// returns date under DD/MM/YYYY format
const char* g_get_date();

// returns signal strength according to module data sheet
uint8_t g_get_rssi();

// returns position from gps module
const char* g_get_location();

// returns number of satellites seen by the gps
const char* g_get_satellites();

// returns altitude in meters
const char* g_get_altitude();

// returns speed in kph
const char* g_get_speed();