#include "longterms.h"
#include "../ATSerial.h"

GSM_RESULT init_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

COMMANDCALLBACK at_init_gsm(ATSerial* as)
{
    as->at_command(F("AT+CFUN=1")); // query full phone functionality, can take up to 10s...

    return init_callback;
}

GSM_RESULT sim_unlocked_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

COMMANDCALLBACK at_sim_unlocked(ATSerial* as)
{
    as->at_command(F("AT+CPIN?")); // query sim unlocked, can take up to 5s...

    return sim_unlocked_callback;
}

GSM_RESULT send_sms_callback(ATSerial* as)
{
    return (as->at_is_response("CMGS") ? GSM_OK : GSM_ERROR);
}

COMMANDCALLBACK at_send_sms(ATSerial* as, const char* number, const char* text)
{
    as->at_command(F("AT+CMGF=1")); // set sms system into text mode
    if(!as->at_get_response())
        return nullptr;
    if(!as->at_is_response_ok())
        return nullptr;

    as->at_command(F("AT+CSCS=\"GSM\"")); // set charset to GSM 7 bit default alphabet
    if(!as->at_get_response())
        return nullptr;
    if(!as->at_is_response_ok())
        return nullptr;

    char str[20];    
    snprintf_P(str, 20, PSTR("\"%s\""), number);

    as->at_command(F("AT+CMGS="), number);
    as->at_text(text);

    return send_sms_callback;
}

GSM_RESULT call_number_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

COMMANDCALLBACK at_call_number(ATSerial* as, const char* number)
{
    as->print(F("ATD")); // ask to call number
    as->print(number);
    as->print(F(";\r")); // don't forget the comma !

    return call_number_callback;
}
