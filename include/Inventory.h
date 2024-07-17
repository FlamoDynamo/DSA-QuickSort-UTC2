#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    // Constructor
    Inventory();

    // Add a new item to the inventory
    void addItem(const Item& item);

    // Remove an item from the inventory by ID
    void removeItem(int id);

    // Update the quantity of an existing item
    void updateItemQuantity(int id, int newQuantity);

    // Search for an item by ID
    Item* findItem(int id);

    // Get the list of all items in the inventory
    std::vector<Item*> getItems() const;

    // Sort the inventory by a specified attribute
    void sortInventory(const std::string& attribute);

private:
    std::vector<Item*> items_;

    // Private helper function for Quick Sort
    void quickSort(std::vector<Item*>& items, int low, int high, const std::string& attribute);

    // Private helper function for partitioning the array during Quick Sort
    int partition(std::vector<Item*>& items, int low, int high, const std::string& attribute);
};

#endif // INVENTORY_H
