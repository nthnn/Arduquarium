#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "module_config.h"
#include "module_lm35dz.h"
#include "module_ph4502c.h"
#include "module_water_sensor.h"

LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.begin(9600);
    Serial.println("Starting Arduquarium...");
  #endif

  pinMode(ARDUQUARIUM_LM35DZ_PIN, INPUT);
  pinMode(ARDUQUARIUM_PH4502C_PH_PIN, INPUT);

  pinMode(ARDUQAURIUM_WATER_PUMP_IN, OUTPUT);
  pinMode(ARDUQUARIUM_WATER_PUMP_OUT, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  float ph_level = read_ph4502c(), temp = read_lm35dz();
  int water_level = read_water_sensor();

  String pad = (water_level <= 99) ? "0" : "";
  pad += (water_level <= 9 ? "0" : "");
  pad += (water_level == 0 ? "0" : "");

  #ifdef ARDUQUARIUM_DEBUG_BUILD
    Serial.print("PH Level: ");
    Serial.print(ph_level, 4);
    Serial.print(" - Temperature: ");
    Serial.print(temp, 4);
    Serial.print(" - Water Level: ");
    Serial.println(water_level);
  #endif

  lcd.clear();
  lcd.print("Water lvl: " + pad + String(water_level));
  lcd.setCursor(0, 1);
  lcd.print(String(temp) + "C    " + String(ph_level) + "pH");

  if(water_level <= 400)

  delay(1000);
}