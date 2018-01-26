#pragma once
#include <Arduino.h>
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef bool (*COMMANDCALLBACK)(ATSerial* as);

#define AT_INIT_GSM_TIMEOUT 10000 
COMMANDCALLBACK at_init_gsm(ATSerial* as);

#define AT_SIM_UNLOCKED_TIMEOUT 5000
COMMANDCALLBACK at_sim_unlocked(ATSerial* as);

#define AT_SEND_SMS_TIMEOUT 60000
COMMANDCALLBACK at_send_sms(ATSerial* as, const char* number,const char* text);

#define AT_CALL_NUMBER_TIMEOUT 20000
COMMANDCALLBACK at_call_number(ATSerial* as, const char* number);
