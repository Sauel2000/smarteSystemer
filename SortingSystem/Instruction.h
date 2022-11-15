#pragma once

#include <Arduino.h>

class Instruction
{
public:
    Instruction(String str);
    int getInstruction();
    int getItem();
private:
    int instruction;
    int item;
};
