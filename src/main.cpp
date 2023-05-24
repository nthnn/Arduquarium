#include <Arduino.h>

#include "module_ph4502c.h"

PH4502C ph4502c;

void setup() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.begin(9600);
    Serial.println("Starting Arduquarium...");
  #endif

  ph4502c = PH4502C(PH4502C_TEMPERATURE_PIN, PH4502C_PH_PIN);
}

void loop() {

}