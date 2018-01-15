#include "module_gsm.h"
#include <SoftwareSerial.h>
#include <sim800l.h>
#include "hardware_config.h"

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    Sim800l gsm;
    SoftwareSerial ss(GSM_SS_RX, GSM_SS_TX);

    void setup()
    {
        ss.begin(9600);
        gsm.init(&ss);
    }

    void update()
    {

    }

    uint8_t get_signal_level()
    {
        return signal_level;
    }
}
