#pragma once
#include <Arduino.h>
#include "Coord.h"

class Item {
public:
    String name;
    bool borrowed;

    Item(String name, int width, int lenght);
    void registerNewItem();
    void removeItem();
    void borrow();
    void unborrow();
private:
    int width;
    int length;
};
