#pragma once
#include <Arduino.h>

// glue code to provide correctly formatted accessors for the widgets

uint8_t g_get_battery_level();

// returns if controller is calibrated or not
bool g_get_compass_data(float* roll, float* pitch /*, float* yaw*/);

// RTC
int32_t g_get_hour();
void g_set_hour(int32_t value);
int32_t g_get_minutes();
void g_set_minutes(int32_t value);
int32_t g_get_day();
void g_set_day(int32_t value);
int32_t g_get_month();
void g_set_month(int32_t value);
int32_t g_get_year();
void g_set_year(int32_t value);

// GSM
// returns signal strength according to module data sheet
uint8_t g_get_signal_level();
bool g_call_number(const char* number);
bool g_send_sms(const char* number);

