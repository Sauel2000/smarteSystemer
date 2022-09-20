#include <Stepper.h>

#include "MotorController.h"
#include "LinearRailSystem.h"
#include "UIController.h"

void setup() {
  Serial.begin(9600);

  UIController uiController;

   LinearRailSystem linearRailSystem;
   linearRailSystem.returnToInitialPosition();

  linearRailSystem.moveTo(2, 2);
  linearRailSystem.fetch();
};

void loop() {
  
}
