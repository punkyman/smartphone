#include "encoder.h"

volatile int8_t encoder_scrolls;
bool encoder_switch;

void encoder_interrupt()
{
    if(digitalRead(ENCODER_DIGITAL_DATA))
    {
        --encoder_scrolls; // CCW
    }
    else
    {
        ++encoder_scrolls; // CW
    }
}

void init()
{
    encoder_scrolls = 0;
    encoder_switch = false;

    pinMode(ENCODER_DIGITAL_CLOCK, INPUT);
    pinMode(ENCODER_DIGITAL_DATA, INPUT);
    pinMode(ENCODER_DIGITAL_SWITCH, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENCODER_DIGITAL_CLOCK), encoder_interrupt, RISING);
}

void encoder_clear_readings()
{
    encoder_scrolls = 0;
}

void encoder_read_values()
{
    encoder_switch = digitalRead(ENCODER_DIGITAL_SWITCH) != HIGH;
}

