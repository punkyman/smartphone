#pragma once
#include <Arduino.h>
#if defined(STM32_MCU_SERIES)
#include <HardwareSerial.h>
#elif defined(__AVR_ARCH__)
#include <SoftwareSerial.h>
#endif

#define AT_SERIAL_TIMEOUT 1000

#define SERIAL_DEBUG

struct ATSerial
{   
    ATSerial(uint8_t receivePin, uint8_t transmitPin);

    int timed_read();

    void at_flush();

    void at_command(const __FlashStringHelper * cmd);
    void at_command(const __FlashStringHelper * cmd, int arg);
    void at_command(const __FlashStringHelper * cmd, const char* arg);

    void at_text(const char* text); // sends a text followed by Ctrl+Z command

    // synchronous answer reading, based on timedRead() implementation
    // default delay is 1000 ms
    bool at_get_response(); 

    // asynchronous answer reading, needs to be checked against the command timeout
    bool at_is_response_available();
  
    // common result parsing
    bool at_is_response(const char* rsp); // text cannot be in progmem here
    bool at_is_response_ok(); // optimisation with the OK text embedded
    bool at_get_response_tag(const char* tag, uint8_t* value);

    String buffer;
#if defined(STM32_MCU_SERIES)
    HardwareSerial& serial;
#elif defined(__AVR_ARCH__)
    SoftwareSerial serial;
#endif
};
