#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

struct ATSerial : SoftwareSerial
{   
    ATSerial(uint8_t receivePin, uint8_t transmitPin);

    bool at_wait_for_ok();
    bool at_get_tag(const char* tag, uint8_t* value);
};
