/*
 Battery.cpp - Battery library
 Copyright (c) 2014 Roberto Lo Giacco.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as 
 published by the Free Software Foundation, either version 3 of the 
 License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Battery.h"
#include <Arduino.h>

Battery::Battery(uint16_t minVoltage, uint16_t maxVoltage, uint8_t sensePin, uint8_t activationPin) {
	this->sensePin = sensePin;
	this->activationPin = activationPin;
	this->minVoltage = minVoltage;
	this->maxVoltage = maxVoltage;
}

void Battery::begin(uint16_t refVoltage, float dividerRatio) {
	this->refVoltage = refVoltage;
	this->dividerRatio = dividerRatio;
#if defined(STM32_MCU_SERIES)
        // ADC has to be enabled per pin on the stm32
    pinMode(this->sensePin, INPUT_ANALOG);  
#else
	pinMode(this->sensePin, INPUT);
#endif
	if (this->activationPin < 0xFF) {
		pinMode(this->activationPin, OUTPUT);
	}
}

uint8_t Battery::level() {
	int16_t sense = this->voltage();
	if (sense <= minVoltage) {
		return 0;
	} else if (sense >= maxVoltage) {
		return 100;
	} else {
		return (unsigned long)(sense - minVoltage) * 100 / (maxVoltage - minVoltage);
	}
}

uint16_t Battery::voltage() {
	if (activationPin != 0xFF) {
		digitalWrite(activationPin, HIGH);
		delayMicroseconds(10); // copes with slow switching activation circuits
	}
	analogRead(sensePin);
	delay(2); // allow the ADC to stabilize
	uint16_t reading = analogRead(sensePin);
#if defined(STM32_MCU_SERIES)
	reading = reading * dividerRatio * refVoltage / 4096; // stm32 happens to have 12bit ADC
#else
	reading = reading * dividerRatio * refVoltage / 1024;
#endif
	if (activationPin != 0xFF) {
		digitalWrite(activationPin, LOW);
	}
	return reading;
}
