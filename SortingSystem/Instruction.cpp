#include "Instruction.h"

Instruction::Instruction(String str) {
    str.trim();

    this->instruction = String(str[0]).toInt();
    this->item = String(str[1]).toInt();
}

int Instruction::getInstruction() {
    return this->instruction;
}

int Instruction::getItem() {
    return this->item;
}
