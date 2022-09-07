#pragma once
#include "Coord.h"
#include "MotorController.h"
#include "Fetcher.h"

class LinearRailSystem {
  public:
    Coord coord_at; // The current position of the linear rail system.
    bool sensorActive = false;

    MotorController motorX;
    MotorController motorY;

    LinearRailSystem(): motorX(2, 3), motorY(4, 5) {
      // Initital coords.
      coord_at.x = 0;
      coord_at.y = 0;
    };

    void returnToInitialPosition() {
      if (!sensorActive) {
        // Enable motors.
        motorX.step(-1 * motorX.getstepsPerRevolution() * motorX.getstepInCoords());
        motorY.step(-1 * motorY.getstepsPerRevolution() * motorY.getstepInCoords());
      } else {
        // Stop motors.
      }
    };

    // Move to another position.
    void moveTo(int x, int y) {
      // Enable motors to move to position.
      motorX.step(x * motorX.getstepsPerRevolution() * motorX.getstepInCoords());
      motorY.step(y * motorY.getstepsPerRevolution() * motorY.getstepInCoords());

      coord_at.x = x;
      coord_at.y = y;

      Serial.println(coord_at.x);
      Serial.println(coord_at.y);
    };

    void fetch() {
      Fetcher fetcher;
      fetcher.fetch();
    }
  private:
};
