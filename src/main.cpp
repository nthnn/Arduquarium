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

<<<<<<< HEAD
  pinMode(ARDUQUARIUM_WATER_PUMP_IN, OUTPUT);
=======
  pinMode(ARDUQAURIUM_WATER_PUMP_IN, OUTPUT);
>>>>>>> e9fbe8fdf9bad055a0d49e31dcf700291123c0ef
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

  water_level_check:
  if(water_level <= ARDUQUARIUM_LOW_LEVEL_WATER) {
    digitalWrite(ARDUQUARIUM_WATER_PUMP_IN, HIGH);
    delay(1000);

    while(read_water_sensor() <= ARDUQUARIUM_LOW_LEVEL_WATER)
      goto water_level_check;
  }
  digitalWrite(ARDUQUARIUM_WATER_PUMP_IN, LOW);

  ph_level_check:
  if(ph_level < 6.5 || ph_level > 7.5) {
    digitalWrite(ARDUQUARIUM_WATER_PUMP_OUT, HIGH);
    delay(1000);

    auto new_ph_val = read_ph4502c();
    while(new_ph_val < 6.5 || new_ph_val > 7.5)
      goto ph_level_check;
  }
  digitalWrite(ARDUQUARIUM_WATER_PUMP_OUT, LOW);

  delay(800);
}