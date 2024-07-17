#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    Inventory();
    // Inventory Management
    void addItem(const Item& item);
    void updateItem(int itemId, const Item& updatedItem);
    void deleteItem(int itemId);
    Item* findItemById(int itemId);
    // Quick Sort Functionality
    void quickSort(std::vector<Item>& items, int low, int high, bool (*compare)(const Item&, const Item&));
    void sortBy(bool (*compare)(const Item&, const Item&)); 
    // Helper Functions for Sorting
    int partition(std::vector<Item>& items, int low, int high, bool (*compare)(const Item&, const Item&));
    void swapItems(Item& item1, Item& item2);
    // Other Inventory Operations (To be implemented)
    // ... 
private:
    std::vector<Item> items_; 
};

#endif // INVENTORY_H
