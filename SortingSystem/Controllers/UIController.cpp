#include "UIController.h"
#include "../Button.h"

UIController::UIController(): lcd(0x27, 16, 2) {
  lcd.init();
  lcd.backlight(); 

  this->showWelcomeMessage(); 

  Button btnX(10); // Create button instance
  Button btnY(11); // Create button instance
  Button btnOk(12); // Create button instance

  coord.x = 0;
  coord.y = 0;

  this->updateChooseItemStatus(coord);

  while (true) {
    if (btnOk.isPressed()) {
      break;
    }

    if (btnX.isPressed()) {
      coord.x++;

      if (coord.x > 2) {
        coord.x = 0;
      }

      this->updateChooseItemStatus(coord);

      delay(100);
    } else if (btnY.isPressed()) {
      coord.y++;

      if (coord.y > 2) {
        coord.y = 0;
      }

      this->updateChooseItemStatus(coord);

      delay(100);
    }
  }
}

void UIController::showWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sort.it ");

  delay(4000);
}

void UIController::showMessage(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);

  lcd.setCursor(0, 1);
  lcd.print(line2);

  delay(1000);
}

void UIController::updateChooseItemStatus(Coord coord) {
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Choose item:");

  lcd.setCursor(0, 1);

  char strBuffer[16];
  sprintf(strBuffer, "at pos (%d, %d)", coord.x, coord.y);

  lcd.print(strBuffer);  
}

Coord UIController::getCoord() {
  return this->coord;
}
