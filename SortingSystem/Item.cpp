#include "Item.h"

Item::Item(int id, String name, int width, int lenght)
{
    this->id = id;
    this->name = name;
    this->width = width;
    this->length = lenght;
    this->borrowed = false;
/**
 * @param id unique identifier, name, width, lenght, borrow state
 * @details Items should not be larger than 10 cm in width or length for this linearRailSystem
*/
}

void Item::borrow() {
    this->borrowed = true;
}

void Item::unborrow() {
    this->borrowed = false;
}

bool Item::isBorrowed() {
    bool isBorrowed = this->borrowed;
    Serial.print(isBorrowed);
    return this->borrowed;
}

int Item::getId() {
    return this->id;
}
