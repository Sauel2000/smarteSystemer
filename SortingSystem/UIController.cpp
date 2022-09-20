#include "UIController.h"
#include <Arduino.h>

UIController::UIController() {
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);

  lcd.print("Sort.it ");

  delay(5000);

  lcd.clear();

  lcd.print("Choose item:");    

  lcd.setCursor(0, 1);
  lcd.print("at pos (0, 1)");
  delay(100);  
}