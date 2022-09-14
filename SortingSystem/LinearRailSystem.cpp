#include <Arduino.h>
#include "LinearRailSystem.h"

LinearRailSystem::LinearRailSystem(): motorX(2, 3), motorY(4, 5), sensorX(10), sensorY(11) {
  // Initital coords.
  this->coordAt.x = 0;
  this->coordAt.y = 0;
}

void LinearRailSystem::returnToInitialPosition(){
  Serial.println("Returning to initial position.");

  bool isInitialPositionX = false;
  bool isInitialPositionY = false;

  while (isInitialPositionX == false || isInitialPositionY == false) {
    if (this->sensorX.isPressed() == false) {
      this->motorX.step(-1 * this->motorX.getstepsPerRevolution() * this->motorX.getstepInCoords());
    } else {
      isInitialPositionX = true;
    }

    if (this->sensorY.isPressed() == false) {
      this->motorY.step(-1 * this->motorY.getstepsPerRevolution() * this->motorY.getstepInCoords());
    } else {
      isInitialPositionY = true;
    }
  }
}

void LinearRailSystem::moveTo(int x, int y){
  // Enable motors to move to position.
  this->motorX.step(x * this->motorX.getstepsPerRevolution() * this->motorX.getstepInCoords());
  this->motorY.step(y * this->motorY.getstepsPerRevolution() * this->motorY.getstepInCoords());

  this->coordAt.x = x;
  this->coordAt.y = y;
}

void LinearRailSystem::fetch(){
  Fetcher fetcher;
  fetcher.fetch();
}
