#include "encoder.h"
#include <hal.h>

volatile int8_t encoder_scrolls;
bool encoder_switch;

#ifdef USE_CLICK_ENCODER

#include "click-encoder/ClickEncoder.h"

HardwareTimer timer(1);
ClickEncoder* clickEncoder;

void encoder_interrupt()
{
    clickEncoder->service();
}

void encoder_init(uint8_t clock_pin, uint8_t data_pin, uint8_t switch_pin)
{
    clickEncoder = new ClickEncoder(clock_pin, data_pin, switch_pin);
    clickEncoder->setAccelerationEnabled(false);

    encoder_scrolls = 0;
    encoder_switch = false;

    timer.setPeriod(1000);
    timer.attachCompare1Interrupt(encoder_interrupt); 
}

void encoder_clear_readings()
{
    encoder_scrolls = 0;
}

void encoder_read_values()
{
    encoder_scrolls = clickEncoder->getValue();
    encoder_switch = clickEncoder->getButton() == ClickEncoder::Clicked;
}

#else

uint8_t encoder_clock_pin, encoder_data_pin, encoder_switch_pin;

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

#endif