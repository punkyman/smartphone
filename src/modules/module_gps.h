#pragma once

#include <Arduino.h>

#define GPS_RX_PIN 3
#define GPS_TX_PIN 4

namespace ModuleGps
{
    void setup();

    void update();

    bool get_location(uint16_t* lat_deg, double* lat_bil, uint16_t* long_deg, double* long_bil);
    
    uint32_t get_satellites();
}
