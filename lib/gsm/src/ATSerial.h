#pragma once
#include <Arduino.h>
class SoftwareSerial;

bool serial_wait_for_ok(SoftwareSerial* ss);
bool serial_get_tag(SoftwareSerial* ss, const char* tag, uint8_t* value);
