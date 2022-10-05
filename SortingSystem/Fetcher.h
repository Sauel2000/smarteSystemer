#pragma once
#include "Controllers/MotorController.h"
//Creating object "Fetcher" for z axis
class Fetcher {
public:
  //Creating object motorZ to move in Zaxis.
  MotorController motorZ;

  Fetcher(): motorZ(6, 7) { // Initialising pins for Z in arduino
  }
  const int getStepsToFetch();

  void fetch() {
    motorZ.step(motorZ.getstepsPerRevolution() * getStepsToFetch());
  }
private:
  const static int stepsToFetch = 5; //Temporary 5 rounds of 360* to reach one box down
};
