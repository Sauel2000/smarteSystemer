#include <Stepper.h>

struct Coord {
  int x;
  int y;
};

class LinearRailSystem {
  public:
    // The current position of the linear rail system.
    Coord coord_at;
    bool sensorActive = false;

    LinearRailSystem(Coord coord_initial) {
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
};

void loop() {
  // put your main code here, to run repeatedly:
  
};
