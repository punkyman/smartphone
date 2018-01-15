#include "sim800l.h"
#include <SoftwareSerial.h>

void Sim800l::init(SoftwareSerial* serial)
{
    ss = serial;
}
