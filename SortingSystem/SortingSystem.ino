#include <Arduino.h>
#include <Stepper.h>

#include "MotorController.h"
#include "LinearRailSystem.h"
#include "UIController.h"

void setup() {
  Serial.begin(9600);

  UIController uiController;

  Coord coord = uiController.getCoord();

  LinearRailSystem linearRailSystem;

  uiController.showMessage("Fetching item at", "(" + String(coord.x) + ", " + String(coord.y) + ")");

  linearRailSystem.returnToInitialPosition();
  linearRailSystem.moveTo(coord.x, coord.y);
  linearRailSystem.fetch();
}

void loop() {
  
}
