#pragma once

class SoftwareSerial;

struct Sim800l
{
    void init(SoftwareSerial* serial);

    SoftwareSerial* ss;
};
