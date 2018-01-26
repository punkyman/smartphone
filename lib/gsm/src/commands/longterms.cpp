#include "longterms.h"
#include "../ATSerial.h"

GSM_RESULT init_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

GSM_RESULT at_init_gsm(ATSerial* as, COMMANDCALLBACK* callback)
{
    as->at_command(F("AT+CFUN=1")); // query full phone functionality, can take up to 10s...
    *callback = init_callback;

    return GSM_OK;
}

GSM_RESULT sim_unlocked_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

GSM_RESULT at_sim_unlocked(ATSerial* as, COMMANDCALLBACK* callback)
{
    as->at_command(F("AT+CPIN?")); // query sim unlocked, can take up to 5s...
    *callback = init_callback;

    return GSM_OK;
}

GSM_RESULT send_sms_callback(ATSerial* as)
{
    return (as->at_is_response("CMGS") ? GSM_OK : GSM_ERROR);
}

GSM_RESULT at_send_sms(ATSerial* as, const char* number, const char* text, COMMANDCALLBACK* callback)
{
    as->at_command(F("AT+CMGF=1")); // set sms system into text mode
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;

    as->at_command(F("AT+CSCS=\"GSM\"")); // set charset to GSM 7 bit default alphabet
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;

    char str[20];    
    snprintf_P(str, 20, PSTR("\"%s\""), number);

    as->at_command(F("AT+CMGS="), number);
    as->at_text(text);

    *callback = send_sms_callback;
    return GSM_OK;
}

GSM_RESULT call_number_callback(ATSerial* as)
{
    return (as->at_is_response_ok() ? GSM_OK : GSM_ERROR);
}

GSM_RESULT at_call_number(ATSerial* as, const char* number, COMMANDCALLBACK* callback)
{
    char str[20];    
    snprintf_P(str, 20, PSTR("%s;"), number); // don't forget the comma !

    as->at_command(F("ATD"), str); // ask to call number

    *callback = init_callback;
    return GSM_OK;
}
