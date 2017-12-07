// ************************************************************************************************************
// I2C Accelerometer ADXL345 
// ************************************************************************************************************
#pragma once

#include <Arduino.h>

#define ADXL345_ADDRESS 0x1D

namespace ModuleAcceleration
{
    extern int16_t accADC[3];
    void setup();

    void upate();
}

