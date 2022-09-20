#include <Stepper.h>

#include "MotorController.h"
#include "LinearRailSystem.h"
#include "UIController.h"

void setup() {
  Serial.begin(9600);

  UIController uiController;

  // LinearRailSystem linearRailSystem;
  // linearRailSystem.returnToInitialPosition();

<<<<<<< HEAD
  linearRailSystem.moveTo(2, 2);
  linearRailSystem.fetch();
};
=======
  // linearRailSystem.moveTo(2, 2);
  // linearRailSystem.fetch();
  // MotorController motorController3(8, 9);
}
>>>>>>> 6add9fa (added UIController class)

void loop() {
  
}
