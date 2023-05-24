#include <Arduino.h>

#include "module_ph4502c.h"

void PH4502C::setup() {
    pinMode(this->to_pin, INPUT);
    pinMode(this->po_pin, INPUT);
}

float PH4502C::read_ph_level() {
    float reading = 0.0f;

    for(int i = 0; i < PH_LEVEL_READING_COUNT; i++) {
        reading += 7 - ((analogRead(this->po_pin) * (5.0 / 1024.0) / 59.16));
        delayMicroseconds(PH_LEVEL_READ_INTERVAL);
    }

    reading /= PH_LEVEL_READING_COUNT;
    return reading;
}

float PH4502C::read_temperature() {
    return (float) analogRead(this->to_pin);
}