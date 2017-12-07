// ************************************************************************************************************
// I2C Gyroscope L3G4200D 
// ************************************************************************************************************
#pragma once

#include <Arduino.h>

#define L3G4200D_ADDRESS 0x69

namespace ModuleGyroscope
{
    extern int16_t gyroADC[3];

    void setup();

    void update();   
}

