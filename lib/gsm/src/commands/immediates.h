#pragma once
#include <Arduino.h>
#include "../result_codes.h"
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// immediate commands
///////////////////////////////////////////////////////////////////////////////
GSM_RESULT at_init(ATSerial* ss); // init is blocking for up to 15s, but we can accept that
GSM_RESULT at_get_signal_level(ATSerial* as, uint8_t* value);
GSM_RESULT at_set_microphone_gain(ATSerial* as, uint8_t value); // range from 0 to 15
