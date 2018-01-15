// ************************************************************************************************************
// I2C Accelerometer ADXL345 
// ************************************************************************************************************
#pragma once

#include <Arduino.h>

namespace ModuleAcceleration
{
    extern int16_t accADC[3];

    void setup();

    void update();
}

