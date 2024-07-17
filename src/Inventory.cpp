#include "Inventory.h"

Inventory::Inventory() {
    // Constructor implementation (optional)
}

void Inventory::addItem(const std::string& sku, const std::string& name, const std::string& brand,
                       const std::string& category, double price, int quantity, const std::string& supplier) {
    Item* newItem = new Item(sku, name, brand, category, price, quantity, supplier);
    items.push_back(newItem);
}

void Inventory::updateItemQuantity(const std::string& sku, int newQuantity) {
    for (Item* item : items) {
        if (item->getSKU() == sku) {
            item->setQuantity(newQuantity);
            return;
        }
    }
}

void Inventory::removeItem(const std::string& sku) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getSKU() == sku) {
            items.erase(it);
            return;
        }
    }
}

Item* Inventory::findItem(const std::string& sku) const {
    for (Item* item : items) {
        if (item->getSKU() == sku) {
            return item;
        }
    }
    return nullptr; // Item not found
}

void Inventory::sortItemsBySKU() {
    sorter.sort(items, 0, items.size() - 1);
}

std::vector<Item*> Inventory::getItems() const {
    return items;
}