#include "encoder.h"
#include <hal.h>

uint8_t encoder_clock_pin, encoder_data_pin, encoder_switch_pin;

volatile int8_t encoder_scrolls;
bool encoder_switch;

void encoder_interrupt()
{
    if(digitalRead(encoder_data_pin))
    {
        --encoder_scrolls; // CCW
    }
    else
    {
        ++encoder_scrolls; // CW
    }
}

void encoder_init(uint8_t clock_pin, uint8_t data_pin, uint8_t switch_pin)
{
    encoder_clock_pin = clock_pin;
    encoder_data_pin = data_pin;
    encoder_switch_pin = switch_pin;

    encoder_scrolls = 0;
    encoder_switch = false;

    pinMode(encoder_clock_pin, INPUT);
    pinMode(encoder_data_pin, INPUT);
    pinMode(encoder_switch_pin, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(encoder_clock_pin), encoder_interrupt, RISING);
}

void encoder_clear_readings()
{
    encoder_scrolls = 0;
}

void encoder_read_values()
{
    encoder_switch = digitalRead(encoder_switch_pin) != HIGH;
}

