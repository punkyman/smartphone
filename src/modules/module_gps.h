#pragma once

#include <Arduino.h>

namespace ModuleGps
{
    void setup();

    void update();

    bool get_location(double* latitude, double* longitude);
    
    uint32_t get_satellites();

    void get_time(uint8_t* hour, uint8_t* minutes);

    void get_date(uint8_t* day,uint8_t* month, uint16_t* year);

    double get_altitude();

    double get_speed();
}
