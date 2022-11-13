#include <Arduino.h>
#include <Stepper.h>

#include "src/controllers/ClawController.h"
#include "src/controllers/ItemController.h"
#include "src/controllers/MotorController.h"
#include "src/controllers/UIController.h"
#include "LinearRailSystem.h"
#include "Item.h"
#include "RFScanner.h"

//RFScanner rfScanner; // Create RFID scanner instance

#define TEST_ROUTINE true

void setup() {
  Serial.begin(9600);

  ItemController itemController;
  itemController.setItem(0, 1, new Item(1, "Star Head", 5, 5));
  itemController.setItem(0, 2, new Item(2, "Flat Head Screw", 5, 5));

  itemController.setItem(1, 0, new Item(3, "Flange Range", 5, 5));
  itemController.setItem(1, 1, new Item(4, "Bugle Head", 5, 5));
  itemController.setItem(1, 2, new Item(5, "Raise Head", 5, 5));

  itemController.setItem(2, 0, new Item(6, "2 Hole Head", 5, 5));
  itemController.setItem(2, 1, new Item(7, "Sentinel Head", 5, 5));
  itemController.setItem(2, 2, new Item(8, "Philips Head", 5, 5));

  //ScanningRutine(itemController);
  if (TEST_ROUTINE == false) {
    mainRoutine(itemController);
  } else {
    testRoutine(itemController);
  }
}
void ScanningRutine(ItemController itemController) {
  RFScanner scanner;
  scanner.init();
  scanner.scan();
  bool result = scanner.getAccess();
 if (result = true) {
  mainRoutine(itemController);
  scanner.setAccess(false);
 }

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
  myClaw.OpenClaw();


  linearRailSystem.fetch(-1);
  linearRailSystem.returnToInitialPosition();

  myClaw.CloseClaw();

  // Restart main routine.
  ScanningRutine(itemController);
}

void testRoutine(ItemController itemController) {
  // Test routine
  LinearRailSystem linearRailSystem;
  //linearRailSystem.returnToInitialPosition(); // Return to initial position
  
  while (Serial.available() == 0) {}

  String str = Serial.readString();
  str.trim();

  int instruction = String(str[0]).toInt();
  int item = String(str[1]).toInt();

  Coord coord = itemController.getCoord(item);

  linearRailSystem.moveTo(0, coord.y); // Move to the item
  linearRailSystem.fetch(1); // Fetch item
  testRoutine(itemController);
  //ClawController myClaw;
  //myClaw.OpenClaw();

  //linearRailSystem.fetch(-1);
  // linearRailSystem.returnToInitialPosition();

  //myClaw.CloseClaw();
}

void loop() {
  // put your main code here, to run repeatedly:
  // rfScanner.scan(); // Scan for RFID tags
}
