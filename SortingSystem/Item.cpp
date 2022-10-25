#include "Item.h"

Item::Item(String name, int width, int lenght)
{
    this->name = name;
    this->width = width;
    this->length = lenght;
    this->borrowed = false;
}

void Item::borrow() {
    this->borrowed = true;
}

void Item::unborrow() {
    this->borrowed = false;
}

bool Item::isBorrowed() {
    Serial.begin(9600);
    bool isBorrowed = this->borrowed;
    Serial.print(isBorrowed);
    return this->borrowed;
}