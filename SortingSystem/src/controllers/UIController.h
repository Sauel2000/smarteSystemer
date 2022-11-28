#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ItemController.h"

#include "../../Coord.h"

/**
 * @brief Class for controlling the user interface
 * Backup UI that fits our A requirements.
 */

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
 
    /**
     * @brief This method is used to display messages on the UI.
     * 
     * @param line1 
     * @param line2 
     */
    void showMessage(String line1, String line2);

    /**
     * @brief Show the current selected item on the UI.
     * 
     * @param coord 
     * @param itemController 
     */
    void updateChooseItemStatus(Coord coord, ItemController itemController);

    /**
     * @brief Get the Coord of the currently selected item.
     * 
     * @return Coord 
     */
    Coord getCoord(); 
private:
    LiquidCrystal_I2C lcd; 
    Coord coord;
};
