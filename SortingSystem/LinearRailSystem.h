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

    void returnToInitialPosition();

    // Move to another position.
    void moveTo(int x, int y);

    // Move in z axis. 
    void fetch();
  private:
};
