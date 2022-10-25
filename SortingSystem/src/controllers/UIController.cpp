#include "UIController.h"
#include "../../Button.h"

UIController::UIController(ItemController itemController): lcd(0x27, 16, 2) {
  lcd.init();
  lcd.backlight(); 

  this->showWelcomeMessage(); 

  Button btnX(10); 
  Button btnY(11); 
  Button btnOk(12); 

  coord.x = 0;
  coord.y = 0;

  this->updateChooseItemStatus(coord, itemController);

  while (true) {
    if (btnOk.isPressed()) {
      break;
    }

    if (btnX.isPressed()) {
      coord.x++;

      if (coord.x > 2) {
        coord.x = 0;
      }

      this->updateChooseItemStatus(coord, itemController);

      delay(100);
    } else if (btnY.isPressed()) {
      coord.y++;

      if (coord.y > 2) {
        coord.y = 0;
      }

      this->updateChooseItemStatus(coord, itemController);

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

void UIController::updateChooseItemStatus(Coord coord, ItemController itemController) {
  lcd.clear();
  lcd.setCursor(0, 0);

  char strBuffer[16];
  sprintf(strBuffer, "Item (%d, %d)", coord.x, coord.y);

  lcd.print(strBuffer);

  lcd.setCursor(0, 1); 

  Item* item = itemController.getItem(coord.x, coord.y);

  if (item != nullptr) {
    lcd.print(item->name);
  }

  if (item->isBorrowed() == true) { //Martin: I added this if statement to check if the item is borrowed or not
    lcd.print(" Borrowed ");
  }
}

Coord UIController::getCoord() {
  return this->coord;
}
