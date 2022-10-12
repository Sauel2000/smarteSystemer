#include <Arduino.h>
#include <Stepper.h>

#include "src/controllers/ClawController.h"
#include "src/controllers/ItemController.h"
#include "src/controllers/MotorController.h"
#include "src/controllers/UIController.h"
#include "LinearRailSystem.h"
#include "Item.h"
//#include "RFScanner.h"

//RFScanner rfScanner; // Create RFID scanner instance

void setup() {
  Serial.begin(9600);

  // 
  ItemController itemController;
  itemController.setItem(0, 1, new Item("Star Head", 5, 5));
  itemController.setItem(0, 2, new Item("Flat Head Screw", 5, 5));

  itemController.setItem(1, 0, new Item("Flange Range", 5, 5));
  itemController.setItem(1, 1, new Item("Bugle Head", 5, 5));
  itemController.setItem(1, 2, new Item("Raise Head", 5, 5));

  itemController.setItem(2, 0, new Item("2 Hole Head", 5, 5));
  itemController.setItem(2, 1, new Item("Sentinel Head", 5, 5));
  itemController.setItem(2, 2, new Item("Philips Head", 5, 5));

  mainRoutine(itemController);
}

void mainRoutine(ItemController itemController) {  
  UIController uiController(itemController);
  
  Coord coord = uiController.getCoord();

  uiController.showMessage("Fetching item at", "(" + String(coord.x) + ", " + String(coord.y) + ")");

  LinearRailSystem linearRailSystem;
  linearRailSystem.returnToInitialPosition(); // Return to initial position

  Item* fetchedItem = itemController.getItem(coord.x, coord.y);
  fetchedItem->borrow();

  // itemController.removeItem(coord.x, coord.y);

  linearRailSystem.moveTo(coord.x, coord.y); // Move to the item
  linearRailSystem.fetch(1); // Fetch item

  ClawController myClaw;
  myClaw.ClawGrab();


  linearRailSystem.fetch(-1);
  linearRailSystem.returnToInitialPosition();

  myClaw.ClawUngrab();

  // Restart main routine.
  mainRoutine(itemController);
}

void loop() {
  // put your main code here, to run repeatedly:
  // rfScanner.scan(); // Scan for RFID tags
}
