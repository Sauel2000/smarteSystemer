#pragma once
#include "Arduino.h"
#include "Coord.h"
#include "src/controllers/MotorController.h"
#include "Fetcher.h"
#include "Button.h"

class LinearRailSystem {
  public:
    Coord coordAt; // The current position of the linear rail system.
    bool sensorActive = false;

    MotorController motorX;
    MotorController motorY;

    Button sensorX;
    Button sensorY;

    LinearRailSystem();

    void returnToInitialPosition();

    // Move to another position.
    void moveTo(int x, int y);

    // Move in z axis. 
    void fetch();
  private:
};
