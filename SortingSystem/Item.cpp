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
