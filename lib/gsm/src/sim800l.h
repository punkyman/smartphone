#pragma once
class SoftwareSerial;

// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
typedef int (*COMMANDCALLBACK)(const char*);

COMMANDCALLBACK Sim800l_init(SoftwareSerial* ss);
COMMANDCALLBACK Sim800l_get_signal_level(SoftwareSerial* ss);
