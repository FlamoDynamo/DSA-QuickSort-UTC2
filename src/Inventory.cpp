#include "Inventory.h"
#include <algorithm> // for std::swap (used in swapItems)

Inventory::Inventory() {}

void Inventory::addItem(const Item& item) {
    items_.push_back(item);
}

void Inventory::updateItem(int itemId, const Item& updatedItem) {
    for (Item& item : items_) {
        if (item.getId() == itemId) {
            item = updatedItem; // Update the item
            return;
        }
    }
}

void Inventory::deleteItem(int itemId) {
    items_.erase(std::remove_if(items_.begin(), items_.end(), 
                                 [itemId](const Item& item) { return item.getId() == itemId; }), 
                 items_.end());
}

Item* Inventory::findItemById(int itemId) {
    for (Item& item : items_) {
        if (item.getId() == itemId) {
            return &item;
        }
    }
    return nullptr; // Not found
}

// --- Quick Sort Implementation --- 
void Inventory::quickSort(std::vector<Item>& items, int low, int high, 
                         bool (*compare)(const Item&, const Item&)) {
    if (low < high) {
        int pi = partition(items, low, high, compare);
        quickSort(items, low, pi - 1, compare);
        quickSort(items, pi + 1, high, compare);
    }
}

int Inventory::partition(std::vector<Item>& items, int low, int high, 
                          bool (*compare)(const Item&, const Item&)) {
    Item pivot = items[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (compare(items[j], pivot)) {
            i++;
            swapItems(items[i], items[j]);
        }
    }
    swapItems(items[i + 1], items[high]);
    return (i + 1);
}

void Inventory::swapItems(Item& item1, Item& item2) {
    std::swap(item1, item2); // Use std::swap for efficiency
}

// --- Sorting Functionality ---

void Inventory::sortBy(bool (*compare)(const Item&, const Item&)) {
    quickSort(items_, 0, items_.size() - 1, compare);
}
