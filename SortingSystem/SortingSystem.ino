#include <Arduino.h>
#include <Stepper.h>

#include "Controllers/ClawController.h"
#include "Controllers/ItemController.h"
#include "Controllers/MotorController.h"
#include "Controllers/UIController.h"
#include "LinearRailSystem.h"
#include "Item.h"
//#include "RFScanner.h"

//RFScanner rfScanner; // Create RFID scanner instance

void setup() {
  Serial.begin(9600);

  // rfScanner.init(); // Initialize RFID scanner

  UIController uiController;
  
  Coord coord = uiController.getCoord();

  LinearRailSystem linearRailSystem;
  uiController.showMessage("Fetching item at", "(" + String(coord.x) + ", " + String(coord.y) + ")");

  linearRailSystem.returnToInitialPosition(); // Return to initial position
  linearRailSystem.moveTo(coord.x, coord.y); // Move to the item
  linearRailSystem.fetch(); // Fetch item

  ClawController myClaw;
  myClaw.ClawGrab();
  myClaw.ClawUngrab();  
}

void loop() {
  // put your main code here, to run repeatedly:
  // rfScanner.scan(); // Scan for RFID tags
}
