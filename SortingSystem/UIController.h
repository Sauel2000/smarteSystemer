#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Coord.h"

class UIController {
public:
    UIController(); // Constructor
    void showWelcomeMessage(); // Show welcome message
    void showMessage(String line1, String line2); // Show message
    void updateChooseItemStatus(Coord coord); // Update choose item status
    Coord getCoord(); // Get coord
private:
    LiquidCrystal_I2C lcd; // Create LCD instance
    Coord coord;
};
