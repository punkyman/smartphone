#pragma once
#include <Arduino.h>
#include "../result_codes.h"
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef GSM_RESULT (*COMMANDCALLBACK)(ATSerial* as);

#define AT_INIT_GSM_TIMEOUT 10000 
GSM_RESULT at_init_gsm(ATSerial* as, COMMANDCALLBACK* callback);

#define AT_SIM_UNLOCKED_TIMEOUT 5000
GSM_RESULT at_sim_unlocked(ATSerial* as, COMMANDCALLBACK* callback);

#define AT_SEND_SMS_TIMEOUT 60000
GSM_RESULT at_send_sms(ATSerial* as, const char* number, const char* text, COMMANDCALLBACK* callback);

#define AT_CALL_NUMBER_TIMEOUT 20000
GSM_RESULT at_call_number(ATSerial* as, const char* number, COMMANDCALLBACK* callback);
