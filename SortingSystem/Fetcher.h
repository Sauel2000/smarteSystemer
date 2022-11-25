#pragma once
#include "src/controllers/MotorController.h"
//Creating object "Fetcher" for z axis
class Fetcher {
public:
  //Creating object motorZ to move in Zaxis.
  MotorController motorZ;

  /**
   * @brief Construct a new Fetcher object
   */
  Fetcher();

  /**
   * @brief Get the numvers of steps to reach item.
   * 
   * @return const int 
   */
  const int getStepsToFetch();

  /**
   * @brief Move the fetcher to the item.
   * 
   * @param direction The direction to move in as a scalar being either 1 or -1.
   */
  void fetch(int direction);
private:
  const static int stepsToFetch = 1; //Temporary 5 rounds of 360* to reach one box down
};
