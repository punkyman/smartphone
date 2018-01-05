#pragma once
#include <Arduino.h>

namespace ModuleRtc
{
    void setup();

    void update();

    void get_time(uint8_t* hour, uint8_t* minutes);

    void get_date(uint8_t* day,uint8_t* month, uint16_t* year);

    void set_time(uint8_t hour, uint8_t minutes);

    void set_date(uint8_t day,uint8_t month, uint16_t year);

    // temperature (!), rough values but it does work!
    float get_temperature();
}
