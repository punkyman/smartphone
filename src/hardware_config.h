#pragma once

///////////////////////////////////////////////////////////////////////////////
// Hardware modules
///////////////////////////////////////////////////////////////////////////////

//#define HARDWARE_ENABLE_SENSORS
#define HARDWARE_ENABLE_GPS
//#define HARDWARE_ENABLE_GSM
//#define HARDWARE_ENABLE_BATTERY
#define HARDWARE_ENABLE_RTC

///////////////////////////////////////////////////////////////////////////////
// Inputs
///////////////////////////////////////////////////////////////////////////////

#define HARDWARE_USE_JOYSTICK
#define HARDWARE_USE_ENCODER

///////////////////////////////////////////////////////////////////////////////
// Displays
///////////////////////////////////////////////////////////////////////////////

#define HARDWARE_USE_SH1106
#define HARDWARE_USE_PCD8544

///////////////////////////////////////////////////////////////////////////////
// I2C addresses
///////////////////////////////////////////////////////////////////////////////

#define ADXL345_ADDRESS 0x53 // acceleration module
#define BMP085_ADDRESS 0x77 // barometer module
#define MAG_ADDRESS 0x1E // magnetic sensor
#define L3G4200D_ADDRESS 0x69 // gyroscope module
#define SH1106_ADDRESS 0x3C
//#define DS3231_I2C_ADDR 0x68 // RTC module, defined internally in ds3231.h

///////////////////////////////////////////////////////////////////////////////
// Pinout
///////////////////////////////////////////////////////////////////////////////

// This module is accessed through SPI, it uses the default pinout of the SPI implementation
// HARDWARE_USE_PCD8544

// These modules are accessed through I2C, so they use the default pinout of Wire library
// HARDWARE_ENABLE_SENSORS
// HARDWARE_ENABLE_RTC
// HARDWARE_USE_SH1106

//#if defined(HARDWARE_ENABLE_GPS)
#define GPS_SS_RX 3
#define GPS_SS_TX 4
//#endif

//#if defined(HARDWARE_ENABLE_GSM)
#define GSM_SS_RX 5
#define GSM_SS_TX 6
//#endif

//#if defined(HARDWARE_ENABLE_BATTERY)
#define BATTERY_ANALOG_READ A2
//#endif

//#if defined(HARDWARE_USE_JOYSTICK)
#define JOYSTICK_ANALOG_X A0
#define JOYSTICK_ANALOG_Y A1
#define JOYSTICK_DIGITAL_SWITCH 2
//#endif

//#if defined(HARDWARE_USE_ENCODER)
#define ENCODER_DIGITAL_CLOCK 2 // needs to be on an interrupt compatible pin
#define ENCODER_DIGITAL_DATA 4
#define ENCODER_DIGITAL_SWITCH 5
//#endif

