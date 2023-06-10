#include <Arduino.h>

#include "arduquarium_config.h"
#include "arduquarium_sensors.h"

float read_lm35dz() {
    int ave = 0;
    for(int i = 0; i < 10; i++) {
        ave += (analogRead(ARDUQUARIUM_LM35DZ_PIN) * 4.88) / 10;
        delayMicroseconds(10);
    }

    return ((float) ave / 10) - 3;
}

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

int read_water_sensor() {
    return analogRead(ARDUQUARIUM_WATER_SENSOR_PIN);
}