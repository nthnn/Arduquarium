#include <Arduino.h>

#include "module_ph4502c.h"

void PH4502C::setup() {
    pinMode(this->to_pin, INPUT);
    pinMode(this->po_pin, INPUT);
}

float PH4502C::read_ph_level() {
    float reading = 0.0f;

    for(int i = 0; i < PH_LEVEL_READING_COUNT; i++) {
        reading += analogRead(this->po_pin);
        delayMicroseconds(PH_LEVEL_READ_INTERVAL);
    }

    reading = 5 / 1024.0 * reading;
    reading /= PH_LEVEL_READING_COUNT;
    reading = PH_LEVEL_PH_CALIBRATION + ((2.5 - reading)) / 0.18;

    return reading;
}

// TODO: Re-calibrate
float PH4502C::read_temperature() {
    return (float) (analogRead(this->to_pin) * (5.0 / 1023.0));
}