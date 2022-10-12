#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ItemController.h"

#include "../../Coord.h"

class UIController {
public:
    UIController(ItemController itemController);
    void showWelcomeMessage(); 
    void showMessage(String line1, String line2);
    void updateChooseItemStatus(Coord coord, ItemController itemController); 
    Coord getCoord(); 
private:
    LiquidCrystal_I2C lcd; 
    Coord coord;
};
