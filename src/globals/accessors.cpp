#include "accessors.h"
#include "hardware_config.h"

#if defined(HARDWARE_ENABLE_SENSORS)
#include "modules/module_barometer.h"
#include "modules/module_compass.h"
#endif
#if defined(HARDWARE_ENABLE_GPS)
#include "modules/module_gps.h"
#endif
#if defined(HARDWARE_ENABLE_GSM)
#include "modules/module_gsm.h"
#endif
#if defined(HARDWARE_ENABLE_BATTERY)
#include "modules/module_battery.h"
#endif
#if defined(HARDWARE_ENABLE_RTC)
#include "modules/module_rtc.h"
#endif

uint8_t g_get_battery_level()
{
#ifdef HARDWARE_ENABLE_BATTERY
    return ModuleBattery::batterylevel;
#else
    return 100;
#endif
}

bool g_get_compass_data(float* roll, float* pitch/*, float* yaw*/)
{
#if defined(HARDWARE_ENABLE_SENSORS)
    *roll = ModuleCompass::magADC[ModuleCompass::ROLL];
    *pitch = -ModuleCompass::magADC[ModuleCompass::PITCH]; // board placement correction
    /* *yaw = ModuleCompass::magADC[ModuleCompass::YAW]; */
    
    float norm = sqrt((*roll * *roll) + (*pitch * *pitch) /*+ (*yaw * *yaw) */);
    *roll /= norm;
    *pitch /= norm;
    /* *yaw /= norm; */

    return !ModuleCompass::calibrateMag;
#else
    *roll = 0.0f;
    *pitch = 0.0f;
    return false;
#endif
}

int32_t g_get_hour()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t hours, minutes;
    ModuleRtc::get_time(&hours, &minutes);
    return hours;
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t hours, minutes;
    ModuleGps::get_time(&hours, &minutes);
    return hours;
#else
    return 12;
#endif
}
void g_set_hour(int32_t value)
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t hours, minutes;
    ModuleRtc::get_time(&hours, &minutes);
    ModuleRtc::set_time(value, minutes);
#else
    return;
#endif
}

int32_t g_get_minutes()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t hours, minutes;
    ModuleRtc::get_time(&hours, &minutes);
    return minutes;
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t hours, minutes;
    ModuleGps::get_time(&hours, &minutes);
    return minutes;
#else
    return 59;
#endif
}
void g_set_minutes(int32_t value)
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t hours, minutes;
    ModuleRtc::get_time(&hours, &minutes);
    ModuleRtc::set_time(hours, value);
#else
    return;
#endif
}


int32_t g_get_day()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    return day;
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t day, month;
    uint16_t year;
    ModuleGps::get_date(&day, &month, &year);
    return day;
#else
    return 21;
#endif
}

void g_set_day(int32_t value)
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    ModuleRtc::set_date(value, month, year);
#else
    return;
#endif
}

int32_t g_get_month()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    return month;
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t day, month;
    uint16_t year;
    ModuleGps::get_date(&day, &month, &year);
    return month;
#else
    return 01;
#endif
}
void g_set_month(int32_t value)
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    ModuleRtc::set_date(day, value, year);
#else
    return;
#endif
}

int32_t g_get_year()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    return year;
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t day, month;
    uint16_t year;
    ModuleGps::get_date(&day, &month, &year);
    return year;
#else
    return 2018;
#endif
}
void g_set_year(int32_t value)
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    ModuleRtc::set_date(day, month, value);
#else
    return;
#endif
}

uint8_t g_get_signal_level()
{
#ifdef HARDWARE_ENABLE_GSM
    // 0             -115  dBm  or  less    
    // 1             -111  dBm  
    // 2...30      -110... -54 dBm 
    // 31            -52  dBm  or  greater  
    // 99            not  known  or  not  detectable  
    return ModuleGsm::get_signal_level();
#else
    return 31;
#endif
}

bool g_call_number(const char* number)
{
#ifdef HARDWARE_ENABLE_GSM
    return ModuleGsm::call_number(number);
#else
    return false;
#endif
}

bool g_send_sms(const char* number)
{
#ifdef HARDWARE_ENABLE_GSM
    return ModuleGsm::send_sms(number, "FBED");
#else
    return false;
#endif
}
