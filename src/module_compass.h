// ************************************************************************************************************
// I2C Compass HMC5883
// ************************************************************************************************************
#pragma once

#include <Arduino.h>

#define MAG_ADDRESS 0x1E

namespace ModuleCompass
{
    extern int16_t  magADC[3];

    void setup();

     // return 1 when news values are available, 0 otherwise
    uint8_t update();
}


