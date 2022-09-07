#include <Stepper.h>

struct Coord {
  int x;
  int y;
};

class MotorController {
  public:
    const static int stepsPerRevolution = 1600;
    const static int stepsInCoords = 10; // Number of steps on the stepper motor needed for +1 in coord system.

    Stepper stepper;

    MotorController(int pin1, int pin2):
      stepper(stepsPerRevolution, pin1, pin2) {
      stepper.setSpeed(200);

      /*for (int i = 0; i < 10; i++) {
        stepper.setSpeed(10 + i * 10);
        stepper.step(1600);
      }*/
    }

    void step(int steps) {
      stepper.step(steps);
    }
  private:
};

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
        motorX.step(-1 * MotorController::stepsPerRevolution * MotorController::stepsInCoords);
        motorY.step(-1 * MotorController::stepsPerRevolution * MotorController::stepsInCoords);
      } else {
        // Stop motors.
      }
    };

    // Move to another position.
    void moveTo(int x, int y) {
      // Enable motors to move to position.
      motorX.step(x * MotorController::stepsPerRevolution * MotorController::stepsInCoords);
      motorY.step(y * MotorController::stepsPerRevolution * MotorController::stepsInCoords);

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

void setup() {
  Serial.begin(9600);

  LinearRailSystem linearRailSystem;
  linearRailSystem.returnToInitialPosition();
  linearRailSystem.moveTo(2, 2);
  linearRailSystem.fetch();
  // MotorController motorController3(8, 9);
};

void loop() {
  
};
