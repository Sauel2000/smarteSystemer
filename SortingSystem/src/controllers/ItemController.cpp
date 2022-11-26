#include <Arduino.h>
#include "../../Coord.h"
#include "ItemController.h"

ItemController::ItemController() { 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->items[i][j] = nullptr;
        }
    }
    /**
     * ItemController should not be larger than 3x3
     * Array objects are pointers to items.
    */
}

void ItemController::setItem(int x, int y, Item* item) {
    delete this->items[x][y];
    this->items[x][y] = item;
    /**
     * @param x position cord, y position cord, Item pointer for array.
    */
}

Item* ItemController::getItem(int x, int y) { 
    return this->items[x][y];
}

void ItemController::removeItem(int x, int y) { 
    delete this->items[x][y];
    this->items[x][y] = nullptr;

}

Coord ItemController::getCoord(int id) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->items[i][j] != nullptr && this->items[i][j]->getId() == id) {
                Coord coord;
                coord.x = i;
                coord.y = j;

                return coord;
                /**
                 * @param unique id of the item
                 * Check if the array place is empty and use the unique id to find correct item
                */
            }
        }
    }

    Coord coord;
    coord.x = 0;
    coord.y = 0;

    return coord;
}
