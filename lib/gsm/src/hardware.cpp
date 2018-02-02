#include "hardware.h"

void gsm_hard_reset(uint8_t reset_pin)
{
    digitalWrite(reset_pin, HIGH);
    delay(HARD_RESET_DURATION);
    digitalWrite(reset_pin, LOW);
}
