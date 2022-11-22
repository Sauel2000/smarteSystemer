#include <Arduino.h>
#include "LinearRailSystem.h"

LinearRailSystem::LinearRailSystem(): motorX(2, 3, 30), motorY(4, 5, 200), sensorX(8), sensorY(9) {
  // Initital coords.
  this->coordAt.x = 0;
  this->coordAt.y = 0;
}

void LinearRailSystem::returnToInitialPosition() {
  Serial.println("Returning to initial position.");

  bool isInitialPositionX = false;
  bool isInitialPositionY = false;
  while (isInitialPositionX == false || isInitialPositionY == false) {
    if (this->sensorX.isPressed() == false) {
      this->motorX.step(-1 * this->motorX.getstepsPerRevolution() * this->motorX.getstepInCoords());
      isInitialPositionX = false;      
    } else {
      isInitialPositionX = true;
    }

    if (this->sensorY.isPressed() == false) {
      this->motorY.step(-1 * this->motorY.getstepsPerRevolution() * this->motorY.getstepInCoords());
        isInitialPositionY = false;
    } else {
      isInitialPositionY = true;
    }

    delay(10);
  }
}

void LinearRailSystem::returnToInitialPositionCoord(Coord coord) {
  this->motorX.step(1 * this->motorX.getstepsPerRevolution() * this->motorX.getstepInCoords() * coord.x);
  this->motorY.step(1 * this->motorY.getstepsPerRevolutionY() * this->motorY.getstepInCoords() * coord.y);
}

void LinearRailSystem::moveTo(int x, int y) {
  
  this->motorX.step(-x * this->motorX.getstepsPerRevolution() * this->motorX.getstepInCoords());
  this->motorY.step(-y * this->motorY.getstepsPerRevolutionY() * this->motorY.getstepInCoords());

  this->coordAt.x = x;
  this->coordAt.y = y;
}

void LinearRailSystem::fetch(int direction = 1) {
  Fetcher fetcher;
  fetcher.fetch(direction);
}
