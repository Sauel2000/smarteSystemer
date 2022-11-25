#pragma once
#include <Arduino.h>
#include "Coord.h"

class Item {
public:
    String name; // The name of the item.
    bool borrowed; // If the item is in a borrowed state.

    /**
     * @brief Construct a new Item object
     * 
     * @param id The id of the item.
     * @param name The name of the item.
     * @param width The width of the item in mm.
     * @param lenght The length of the item in mm.
     */
    Item(int id, String name, int width, int lenght);

    /**
     * @brief Set the item as borrowed.
     */
    void borrow();

    /**
     * @brief Set the item as returned.
     */
    void unborrow();

    /**
     * @brief Checks if the item is borrowed.
     * 
     * @return bool
     */
    bool isBorrowed();

    /**
     * @brief Get the id of the item.
     * 
     * @return int 
     */
    int getId();
private:
    int width; // The width of the item in mm.
    int length; // The length of the item in mm.
    int id; // The id of the item.
};
