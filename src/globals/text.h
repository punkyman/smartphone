#pragma once
#include <Arduino.h>

// Getters that returns formatted data, mostly used to avoid code duplication
// An internal buffer is used to provide a valid string

const char* g_get_temperature(); // returns temperature in format **.**C

const char* g_get_pressure(); // returns pressure in format *** hPa

const char* g_get_location(); // returns position from gps module in format N** E**

const char* g_get_satellites(); // returns number of satellites seen by the gps

const char* g_get_altitude(); // returns altitude in meters in format ****m

const char* g_get_speed(); // returns speed in kph

const char* g_get_clock(); // returns clock under format HH:MM

const char* g_get_date(); // returns date under DD/MM/YYYY format