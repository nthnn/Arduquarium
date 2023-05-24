#include <Arduino.h>

#include "module_ph4502c.h"

float PH4502C::read_ph_level() {
    float reading = 0.0f;

    for(int i = 0; i < PH_LEVEL_READING_COUNT; i++) {
        reading += analogRead(this->po_pin);
        delayMicroseconds(PH_LEVEL_READ_INTERVAL);
    }

    reading /= PH_LEVEL_READING_COUNT;
    return reading;
}

float PH4502C::read_temperature() {
    return analogRead(this->to_pin);
}