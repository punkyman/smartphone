#pragma once
#include <Arduino.h>
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// immediate commands
///////////////////////////////////////////////////////////////////////////////
bool at_init(ATSerial* ss); // init is blocking for up to 15s, but we can accept that
bool at_get_signal_level(ATSerial* as, uint8_t* value);
bool at_set_microphone_gain(ATSerial* as, uint8_t value); // range from 0 to 15
