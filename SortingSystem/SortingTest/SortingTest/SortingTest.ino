#include <Stepper.h>        //We have included Stepper.h to write less code for the stepper motors.
const int pin1 = 2;
const int pin2 = 3;

class MotorController {
  public:
    const static int stepsPerRevolution = 1600;
    // Number of steps on the stepper motor needed for +1 in coord system.
    const int stepsInCoords = stepsPerRevolution * 10;
    Stepper stepper;

    //Contructor for MotorController
    MotorController(int pin1, int pin2):        
      stepper(stepsPerRevolution, pin1, pin2) {
      stepper.setSpeed(100);
      stepper.step(1600);
      }
  private:
};
class LinearRailSystem {
  public:
  MotorController motorX;
  MotorController motorY;
  MotorController motorZ;
  LinearRailSystem(int x) 
  : motorX(2,3), motorY(4,5), motorZ(8,9) {
    
  }
  private:
};
void setup() {
  // put your setup code here, to run once:

};
void loop() {
  // put your main code here, to run repeatedly:
  //MotorController motorX(2, 3);    
  //MotorController motorY(4, 5);
  //MotorController motorZ(8, 9);

  LinearRailSystem linearRailSystem(1);
  

  //XYController.MoveTo(1,1)
};
