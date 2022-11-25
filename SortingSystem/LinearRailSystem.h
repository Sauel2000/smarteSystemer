#pragma once
#include "Arduino.h"
#include "Coord.h"
#include "src/controllers/MotorController.h"
#include "Fetcher.h"
#include "Button.h"

class LinearRailSystem {
  public:
    Coord coordAt; // The current position of the linear rail system.
    bool sensorActive = false; // The state of the inital position sensor.

    MotorController motorX; // The motor controller for the X axis.
    MotorController motorY; // The motor controller for the Y axis.

    Button sensorX; // The sensor for the x axis initial position.
    Button sensorY; // The sensor for the y axis initial position.

    /**
     * @brief Construct a new Linear Rail System object.
     */
    LinearRailSystem();

    /**
     * @brief Returns the linear rail system to a known state, the initial starting position.
     * It uses sensors to check if the linear rail system is at the initial position.
     */
    void returnToInitialPosition();

    /**
     * @brief Returns the linear rail system to a known, initial state.
     * This method does not use sensors to check if the linear rail system is at the initial position,
     * but rather a specific coordinate that should correspond to the initial position.
     * @param coord The coordinate to return to.
     */
    void returnToInitialPositionCoord(Coord coord);

    /**
     * @brief Move the linear rail system to a specific coordinate.
     * @param coord The coordinate to move to.
     * 
     * @param x 
     * @param y 
     */
    void moveTo(int x, int y);

    /**
     * @brief Move the linear rail system in the z axis.
     * 
     * @param direction The direction to move in as a scalar being either 1 or -1.
     */
    void fetch(int direction);
  private:
};
