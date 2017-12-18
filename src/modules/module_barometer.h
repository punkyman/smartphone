// ************************************************************************************************************
// I2C Barometer BOSCH BMP085
// ************************************************************************************************************
#pragma once

#include <Arduino.h>

#define BMP085_ADDRESS 0x77 // I2C address of BMP085
//#define BARO_TAB_SIZE 2

namespace ModuleBarometer
{
  extern int32_t baroPressure;
  extern int16_t baroTemperature; // temp in 0.01 deg
  extern int32_t baroPressureSum;

    void setup();

    //return 0: no data available, no computation ;  1: new value available  ; 2: no new value, but computation time
    uint8_t update();
}