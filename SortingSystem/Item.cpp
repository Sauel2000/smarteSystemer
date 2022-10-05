#include "Item.h"


Item::Item(String name, int idNum, Coord itemCord, int width, int height, int lenght)
{
    this->name = name;
    this->idNum = idNum; 
    this->itemCord = itemCord;
    this->width = width;
    this->height = height;
    this->length = lenght;
}