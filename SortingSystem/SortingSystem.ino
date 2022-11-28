#include <Arduino.h>
#include <Stepper.h>

#include "src/controllers/ClawController.h"
#include "src/controllers/ItemController.h"
#include "src/controllers/MotorController.h"
#include "src/controllers/UIController.h"
#include "LinearRailSystem.h"
#include "Item.h"
#include "RFScanner.h"
#include "Instruction.h"

RFScanner rfScanner; // Create RFID scanner instance

ItemController itemController;

void setup() {
  Serial.begin(9600);

  itemController.setItem(0, 1, new Item(1, "Red lego", 5, 5));
  itemController.setItem(0, 2, new Item(2, "Green lego", 5, 5));
  itemController.setItem(0, 3, new Item(3, "Yellow Lego", 5, 5));

  itemController.setItem(1, 1, new Item(4, "Lego", 5, 5));
  itemController.setItem(1, 2, new Item(5, "Lego", 5, 5));
  itemController.setItem(1, 3, new Item(6, "Lego", 5, 5));

  itemController.setItem(2, 1, new Item(7, "Lego", 5, 5));
  itemController.setItem(2, 2, new Item(8, "Lego", 5, 5));
  itemController.setItem(2, 3, new Item(9, "Lego", 5, 5));

  LinearRailSystem linearRailSystem;

  mainRoutine();
}

void ScanningRutine() {
  RFScanner scanner;
  scanner.init();
  scanner.scan();

  bool result = scanner.getAccess();

  if (result = true) {
    scanner.setAccess(false);
  }
}

void routineFetchItem(Coord coord, Instruction instruction, LinearRailSystem linearRailSystem) {
    coord = itemController.getCoord(instruction.getItem());
    linearRailSystem.fetch(1); // Fetch upwards
    linearRailSystem.moveTo(coord.x, coord.y);

    ClawController myClaw;
    myClaw.OpenClaw();

    linearRailSystem.fetch(-1); //FETHCER DOWN
    
    myClaw.CloseClaw();
    
    linearRailSystem.fetch(1); //FETHCER
    linearRailSystem.returnToInitialPositionCoord(coord);
    
    linearRailSystem.fetch(-1); 
    myClaw.OpenClaw();
    
    itemController.getItem(coord.x, coord.y)->borrow();

    // routineFetchItem(coord, instruction, linearRailSystem);
}

void routineReturnItem(Coord coord, Instruction instruction, LinearRailSystem linearRailSystem) {
    coord = itemController.getCoord(instruction.getItem());
    ClawController myClaw;
    myClaw.CloseClaw();
    
    linearRailSystem.fetch(1); //FETHCER upwards
    linearRailSystem.moveTo(coord.x, coord.y);
    linearRailSystem.fetch(-1); //FETHCER DOWN
    myClaw.OpenClaw();

    linearRailSystem.fetch(1); 
    itemController.getItem(coord.x, coord.y)->unborrow();
    linearRailSystem.returnToInitialPositionCoord(coord);
    linearRailSystem.fetch(-1);
}

void mainRoutine() {
  ScanningRutine();

  LinearRailSystem linearRailSystem;
  //linearRailSystem.returnToInitialPosition(); // Return to initial position
  
  while (Serial.available() == 0) {}

  Instruction instruction = Instruction(Serial.readString());

  Coord coord;

  switch (instruction.getInstruction()) {
    // Fetch item.
    case 0:
    routineFetchItem(coord, instruction, linearRailSystem);
      break;
    // Return item.
    case 1:
    routineReturnItem(coord, instruction,linearRailSystem);
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // rfScanner.scan(); // Scan for RFID tags
}
