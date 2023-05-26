#include <Arduino.h>

#include "module_config.h"
#include "module_water_sensor.h"

int read_water_sensor() {
    return analogRead(ARDUQUARIUM_WATER_SENSOR_PIN);
}