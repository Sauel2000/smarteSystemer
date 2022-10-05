#include <Arduino.h>

#include "../../Coord.h"
#include "ItemController.h"

ItemController::ItemController() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Coord coord;
            coord.x = 1;
            coord.y = 1;

            this->items[i][j] = new Item("Item", 1, coord, 100, 100, 10);
        }
    }

    Serial.println(this->items[0][0]->name);
}

void ItemController::setItem(int x, int y, Item* item) {
    delete this->items[x][y];
 
    this->items[x][y] = item;
}