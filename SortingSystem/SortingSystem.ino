#include <Stepper.h>

#include "MotorController.h"
#include "LinearRailSystem.h"

void setup() {
  Serial.begin(9600);

  LinearRailSystem linearRailSystem;
  linearRailSystem.returnToInitialPosition();

  // linearRailSystem.moveTo(2, 2);
  // linearRailSystem.fetch();
  // MotorController motorController3(8, 9);
};

void loop() {
  
};
