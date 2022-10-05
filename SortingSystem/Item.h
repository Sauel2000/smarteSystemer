#pragma once
#include <Arduino.h>
#include "Coord.h"

class Item {
public:
    Item(String name, int idNum, Coord itemCord, int width, int height, int lenght);
    void registerNewItem();
    void removeItem();
private:
    String name;
    int idNum;
    Coord itemCord;
    int width;
    int height;
    int length;
};
