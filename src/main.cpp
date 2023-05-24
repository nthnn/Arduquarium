#include <Arduino.h>

#include "module_ph4502c.h"

PH4502C ph4502c(PH4502C_TEMPERATURE_PIN, PH4502C_PH_PIN);

void setup() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.begin(9600);
    Serial.println("Starting Arduquarium...");
  #endif

  ph4502c.setup();
}

void loop() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.print("PH Level: ");
    Serial.println(ph4502c.read_ph_level(), 4);
    Serial.println("Water Temperature: " + String(ph4502c.read_temperature()));
  #endif

  delay(1000);
}