#pragma once

#include "../../Item.h"

class ItemController {
public:
    Item* items[3][3];

    ItemController();
    void setItem(int x, int y, Item* item);
    Item* getItem(int x, int y);
    void removeItem(int x, int y);
private:

};