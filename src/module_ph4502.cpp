#include <Arduino.h>

#include "module_ph4502c.h"

float read_ph4502c() {
    float reading = 0.0f;

    for(int i = 0; i < ARDUQUARIUM_PH_LEVEL_READING_COUNT; i++) {
        reading += analogRead(ARDUQUARIUM_PH4502C_PH_PIN);
        delayMicroseconds(ARDUQUARIUM_PH_LEVEL_READ_INTERVAL);
    }

    reading = 5 / 1024.0 * reading;
    reading /= ARDUQUARIUM_PH_LEVEL_READING_COUNT;
    reading = ARDUQUARIUM_PH_LEVEL_PH_CALIBRATION + ((2.5 - reading)) / 0.18;

    return reading;
}