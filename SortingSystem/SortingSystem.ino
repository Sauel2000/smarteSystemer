#include <Stepper.h>

struct Coord {
  int x;
  int y;
};

class MotorController {
  public:
    const static int stepsPerRevolution = 1600;
    // Number of steps on the stepper motor needed for +1 in coord system.
    const int stepsInCoords = stepsPerRevolution * 10;
    Stepper stepper;

    MotorController(int pin1, int pin2):
      stepper(stepsPerRevolution, pin1, pin2) {
      stepper.setSpeed(100);

      for (int i = -1; i < 2; i++) {
        stepper.step(1600 * i);
      } 
    }
  private:
};

class LinearRailSystem {
  public:
    // The current position of the linear rail system.
    Coord coord_at;
    bool sensorActive = false;
    MotorController motorX;
    MotorController motorY;

    LinearRailSystem(Coord coord_initial):
      motorX(2, 3), motorY(4, 5) {
      coord_at.x = coord_initial.x;
      coord_at.y = coord_initial.y;
    };

    void ReturnToInitialPosition() {
      if (!sensorActive) {
        // Enable motors. 
      } else {
        // Stop motors.
      }
    }

    // Move to another position.
    void MoveTo(Coord coord_move_to) {
      // Enable motors to move to position.
      coord_at.x = coord_move_to.x;
      coord_at.y = coord_move_to.y;
    };
  private:
};

void setup() {
  // put your setup code here, to run once:
  Coord coord;
  coord.x = 0;
  coord.y = 0;

  LinearRailSystem linearRailSystem(coord);
  // MotorController motorController3(8, 9);    
};

void loop() {
  // put your main code here, to run repeatedly:
  
};
