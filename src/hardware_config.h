#pragma once

///////////////////////////////////////////////////////////////////////////////
// Hardware modules
///////////////////////////////////////////////////////////////////////////////

//#define HARDWARE_ENABLE_SENSORS
//#define HARDWARE_ENABLE_GPS
#define HARDWARE_ENABLE_GSM
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

///////////////////////////////////////////////////////////////////////////////
// Pinout
///////////////////////////////////////////////////////////////////////////////

// This module is accessed through SPI, it uses the pinout of the SPI implementation
// in adafruit_wrapper.cpp : SCK : 13, MOSI : 11, DC : 7, CS : 8, RST : 9
// HARDWARE_USE_PCD8544

// These modules are accessed through I2C, they use the default pinout of Wire library
// on arduino mini : SDA : A4, SCL : A5
// HARDWARE_ENABLE_SENSORS
// HARDWARE_ENABLE_RTC
// HARDWARE_USE_SH1106

#define GPS_SS_RX 3
#define GPS_SS_TX 4

#define GSM_SS_RX 5
#define GSM_SS_TX 6

#define BATTERY_ANALOG_READ A2

#define JOYSTICK_ANALOG_X A0
#define JOYSTICK_ANALOG_Y A1
#define JOYSTICK_DIGITAL_SWITCH 2

#define ENCODER_DIGITAL_CLOCK 2 // needs to be on an interrupt compatible pin, on arduino mini : 2 or 3
#define ENCODER_DIGITAL_DATA 4
#define ENCODER_DIGITAL_SWITCH 5
