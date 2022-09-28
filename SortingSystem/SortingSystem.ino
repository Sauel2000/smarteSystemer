#include <Arduino.h>
#include <Stepper.h>
#include "MotorController.h"
#include "LinearRailSystem.h"
#include "UIController.h"
//#include "RFScanner.h"

//RFScanner rfScanner; // Create RFID scanner instance

void setup() {
  Serial.begin(9600);

  // rfScanner.init(); // Initialize RFID scanner

  UIController uiController;
  
  Coord coord = uiController.getCoord();

  LinearRailSystem linearRailSystem;
  uiController.showMessage("Fetching item at", "(" + String(coord.x) + ", " + String(coord.y) + ")");

  // ClawController myClaw;
  // myClaw.ClawGrab();

  linearRailSystem.returnToInitialPosition(); // Return to initial position
  linearRailSystem.moveTo(coord.x, coord.y); // Move to the item
  linearRailSystem.fetch(); // Fetch item

}

void loop() {
  // put your main code here, to run repeatedly:
  // rfScanner.scan(); // Scan for RFID tags
}
