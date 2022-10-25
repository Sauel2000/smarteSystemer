#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ItemController.h"

#include "../../Coord.h"

class UIController {
public:
    /*
    * @desc This method is used to initialize the UIController.
    *@param
    * - itemController: A pointer to the itemController
    * @return void
    */
    UIController(ItemController itemController);
    /*
    * @desc This method is used to update and display the UI.
    * @return void
    */
    void showWelcomeMessage(); 
    void showMessage(String line1, String line2);
    void updateChooseItemStatus(Coord coord, ItemController itemController); 
    Coord getCoord(); 
private:
    LiquidCrystal_I2C lcd; 
    Coord coord;
};
