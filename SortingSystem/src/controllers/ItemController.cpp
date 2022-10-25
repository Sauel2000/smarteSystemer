#include <Arduino.h>
#include "../../Coord.h"
#include "ItemController.h"

ItemController::ItemController() { 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->items[i][j] = nullptr;
        }
    }
}

void ItemController::setItem(int x, int y, Item* item) { 
    delete this->items[x][y]; 
    this->items[x][y] = item; 
}

Item* ItemController::getItem(int x, int y) { // Returns a pointer to the item at the spesific coordinate
    return this->items[x][y];
}

void ItemController::removeItem(int x, int y) { // Deletes the item from the heap and sets the pointer to nullptr
    delete this->items[x][y];
    this->items[x][y] = nullptr;
}