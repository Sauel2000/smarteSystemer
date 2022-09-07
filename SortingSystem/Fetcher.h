#pragma once

#include "MotorController.h"

class Fetcher {
public:
  MotorController motorZ;
  const static int stepsToFetch = 5;

  Fetcher(): motorZ(8, 9) {
    
  }

  void fetch() {
    motorZ.step(MotorController::stepsPerRevolution * Fetcher::stepsToFetch);
  }
};
