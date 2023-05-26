#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "module_lm35dz.h"
#include "module_ph4502c.h"

LiquidCrystal_I2C lcd(0x27, 16, 4);
PH4502C ph4502c(PH4502C_TEMPERATURE_PIN, PH4502C_PH_PIN);

void setup() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.begin(9600);
    Serial.println("Starting Arduquarium...");
  #endif

  pinMode(ARDUQUARIUM_LM35DZ_PIN, INPUT);
  ph4502c.setup();

  lcd.init();
  lcd.backlight();
}

void loop() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.print("PH Level: ");
    Serial.println(ph4502c.read_ph_level(), 4);
    Serial.println("Water Temperature: " + String(ph4502c.read_temperature()));
    Serial.println("Temperature: " + String(read_lm35dz()));
  #endif

  lcd.clear();
  lcd.print("pH: " + String(ph4502c.read_ph_level()));

  delay(1000);
}