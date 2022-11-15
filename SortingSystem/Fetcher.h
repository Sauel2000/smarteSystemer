#pragma once
#include "src/controllers/MotorController.h"
//Creating object "Fetcher" for z axis
class Fetcher {
public:
  //Creating object motorZ to move in Zaxis.
  MotorController motorZ;

  Fetcher(): motorZ(6, 7, 20) { // Initialising pins for Z in arduino
  }
  const int getStepsToFetch();

  void fetch(int direction) {
    motorZ.step(direction * motorZ.getstepsPerRevolutionZ());
  }
private:
  const static int stepsToFetch = 1; //Temporary 5 rounds of 360* to reach one box down
};
