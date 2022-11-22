#pragma once

#include "../../Item.h"
/* When programming on the Arduino it is generally reccommended to not use
heap allocation (new or malloc), this is because the Arduino has very low memory storage,
and it is harder to know how much memory is used if it is dynamically allocated.
In our case we decided to use new, but only because we have looked at the potential memory usage. */
class ItemController {
public:
    /*
    * Pointer in 2D array that holds the items in the system.
    */
    Item* items[4][4]; // Pointer 2D array that holds the items
    
    /*
    * @desc This method is used to get an item at a specific coordinate.
    * @param
    * - x: The x coordinate of the item
    * - y: The y coordinate of the item
    * @return Item*: A pointer to the item at the coordinate
    */
    ItemController(); 
    
    /*
    * @desc This method is used to set an item at a specific coordinate.
    * @param
    * - x: The x coordinate of the item
    * - y: The y coordinate of the item
    * - item: A pointer to the item to be set
    * @return void
    */
    void setItem(int x, int y, Item* item); 
    
    /*
    * @desc This method is used to remove an item at a specific coordinate.
    * @param
    * - x: The x coordinate of the item
    * - y: The y coordinate of the item
    * @return void
    */
    Item* getItem(int x, int y);
    
    /*
    * @desc This method is used to remove an item at a specific coordinate.
    * @param
    * - x: The x coordinate of the item
    * - y: The y coordinate of the item
    * @return void
    */
    void removeItem(int x, int y);

    Coord getCoord(int id);
private:

};
