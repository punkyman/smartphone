#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

struct ATSerial : SoftwareSerial
{   
    ATSerial(uint8_t receivePin, uint8_t transmitPin);

    void serial_update();
    bool serial_at_response_available();
    String serial_at_read_response();

    bool at_get_ok();
    bool at_get_tag(const char* tag, uint8_t* value);

    bool at_stop_messages();
    bool at_resume_messages();

    String buffer;
};
