#pragma once

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

#define GSM_SS_RX 4
#define GSM_SS_TX 3
#define GSM_RESET PB8

#define BATTERY_ANALOG_READ PA3

#define JOYSTICK_ANALOG_X PA0
#define JOYSTICK_ANALOG_Y PA1
#define JOYSTICK_DIGITAL_SWITCH PB9

#define ENCODER_DIGITAL_CLOCK PB3 // needs to be on an interrupt compatible pin, on arduino mini : 2 or 3
#define ENCODER_DIGITAL_DATA PB4
#define ENCODER_DIGITAL_SWITCH PB5