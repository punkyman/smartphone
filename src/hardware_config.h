#pragma once

///////////////////////////////////////////////////////////////////////////////
// Hardware modules
///////////////////////////////////////////////////////////////////////////////

#define HARDWARE_ENABLE_SENSORS
#define HARDWARE_ENABLE_GPS
#define HARDWARE_ENABLE_GSM
#define HARDWARE_ENABLE_BATTERY
#define HARDWARE_ENABLE_RTC

///////////////////////////////////////////////////////////////////////////////
// Inputs
///////////////////////////////////////////////////////////////////////////////

#define HARDWARE_USE_JOYSTICK
#define HARDWARE_USE_ENCODER

///////////////////////////////////////////////////////////////////////////////
// Displays
///////////////////////////////////////////////////////////////////////////////

// This has to be done in adafruit_wrapper for now ...
//#define HARDWARE_USE_SH1106
//#define HARDWARE_USE_PCD8544

///////////////////////////////////////////////////////////////////////////////
// I2C addresses
///////////////////////////////////////////////////////////////////////////////

#define ADXL345_ADDRESS 0x53 // acceleration module
#define BMP085_ADDRESS 0x77 // barometer module
#define MAG_ADDRESS 0x1E // magnetic sensor
#define L3G4200D_ADDRESS 0x69 // gyroscope module
#define SH1106_ADDRESS 0x3C
//#define DS3231_I2C_ADDR 0x68 // RTC module, defined internally in ds3231.h

#if defined(STM32_MCU_SERIES)
#include "hardware_config_stm32.h"
#elif defined(__AVR_ARCH__)
#include "hardware_config_avr.h"
#endif
