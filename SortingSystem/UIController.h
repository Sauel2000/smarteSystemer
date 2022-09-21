#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Coord.h"

class UIController {
public:
    UIController();
    void showWelcomeMessage();
    void showMessage(String line1, String line2);
    void updateChooseItemStatus(Coord coord);
    Coord getCoord();
private:
    LiquidCrystal_I2C lcd;
    Coord coord;
};
