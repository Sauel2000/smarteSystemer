#include "UIController.h"
#include "Button.h"
#include "pitches.h"

uint8_t duck[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

UIController::UIController(): lcd(0x27, 16, 2) {
  lcd.init();
  lcd.backlight();

  this->showWelcomeMessage();

  Button btnX(6);
  Button btnY(7);
  Button btnOk(8);

  coord.x = 0;
  coord.y = 0;

  this->updateChooseItemStatus(coord);

  while (true) {
    if (btnOk.isPressed()) {
      this->playWelcomeTune();
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
  lcd.createChar(0, duck);
  lcd.setCursor(0, 0);
  lcd.home();

  lcd.print("Sort.it ");
  lcd.write(0);

  this->playWelcomeTune();

  delay(4000);
}

// notes in the melody:
int melody[] = {
  NOTE_C3, NOTE_G4, NOTE_B3, NOTE_A3, NOTE_D3, 0, NOTE_C3, NOTE_E4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void UIController::playWelcomeTune() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(9, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(9);
  }
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
