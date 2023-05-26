#include <Arduino.h>

#include "module_config.h"
#include "module_lm35dz.h"

float read_lm35dz() {
    int ave = 0;
    for(int i = 0; i < 10; i++) {
        ave += (analogRead(ARDUQUARIUM_LM35DZ_PIN) * 4.88) / 10;
        delayMicroseconds(10);
    }

    return ((float) ave / 10) - 3;
}