#include "LinearRailSystem.h"

void LinearRailSystem::returnToInitialPosition(){
      if (!sensorActive) {
        // Enable motors.
        motorX.step(-1 * motorX.getstepsPerRevolution() * motorX.getstepInCoords());
        motorY.step(-1 * motorY.getstepsPerRevolution() * motorY.getstepInCoords());
      } else {
        // Stop motors.
      }
}

void LinearRailSystem::moveTo(int x, int y){
    // Enable motors to move to position.
      motorX.step(x * motorX.getstepsPerRevolution() * motorX.getstepInCoords());
      motorY.step(y * motorY.getstepsPerRevolution() * motorY.getstepInCoords());

      coord_at.x = x;
      coord_at.y = y;

    //  Serial.println(coord_at.x);
   //   Serial.println(coord_at.y);
}

void LinearRailSystem::fetch(){
        Fetcher fetcher;
      fetcher.fetch();
}