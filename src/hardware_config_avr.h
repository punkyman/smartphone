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
#define GSM_RESET 6

#define BATTERY_ANALOG_READ A2

#define JOYSTICK_ANALOG_X A0
#define JOYSTICK_ANALOG_Y A1
#define JOYSTICK_DIGITAL_SWITCH 2

#define ENCODER_DIGITAL_CLOCK 2 // needs to be on an interrupt compatible pin, on arduino mini : 2 or 3
#define ENCODER_DIGITAL_DATA 5
#define ENCODER_DIGITAL_SWITCH 6
