#pragma once
#include <Arduino.h>
#include "Coord.h"

class Item {
public:
    String name;
    bool borrowed;

    Item(int id, String name, int width, int lenght);
    void registerNewItem();
    void removeItem();
    void borrow();
    void unborrow();
    bool isBorrowed();
    int getId();
private:
    int width;
    int length;
    int id;
};
