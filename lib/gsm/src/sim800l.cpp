#include "sim800l.h"
#include <SoftwareSerial.h>


int init_callback(const char* str)
{
    return 0;
}

COMMANDCALLBACK Sim800l_init(SoftwareSerial* ss)
{
    ss->print(F("AT\r\n"));
    return init_callback;
}

int get_signal_level_callback(const char* str)
{
    return 0;
}

COMMANDCALLBACK Sim800l_get_signal_level(SoftwareSerial* ss)
{
    ss->print(F("AT+CSQ\r\n"));
    return get_signal_level_callback;
}
