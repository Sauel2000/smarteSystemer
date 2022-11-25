#pragma once

#include <Arduino.h>

/*
* This class is used to store instructions for the sorting system.
*/

class Instruction
{
public:
    /**
    * @brief Initialize the Instruction with a string consisting of two characters.
    * The first character is the instruction type, the second character is the instruction value.
    * @param str The string to initialize the instruction with.
    */
    Instruction(String str);

    /**
     * @brief Get the instruction type.
     * @return int
     */
    int getInstruction();

    /**
     * @brief Get the instruction value.
     * 
     * @return int 
     */
    int getItem();
private:
    int instruction;
    int item;
};
