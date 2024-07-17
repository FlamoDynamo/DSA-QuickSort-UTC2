#include "Inventory.h"

Inventory::Inventory() {}

void Inventory::addItem(const Item& item) {
    items_.push_back(new Item(item));
}

void Inventory::removeItem(int id) {
    for (size_t i = 0; i < items_.size(); ++i) {
        if (items_[i]->getId() == id) {
            delete items_[i];
            items_.erase(items_.begin() + i);
            return;
        }
    }
}

void Inventory::updateItemQuantity(int id, int newQuantity) {
    for (size_t i = 0; i < items_.size(); ++i) {
        if (items_[i]->getId() == id) {
            items_[i]->setQuantity(newQuantity);
            return;
        }
    }
}

Item* Inventory::findItem(int id) {
    for (size_t i = 0; i < items_.size(); ++i) {
        if (items_[i]->getId() == id) {
            return items_[i];
        }
    }
    return nullptr;
}

std::vector<Item*> Inventory::getItems() const {
    return items_;
}

void Inventory::sortInventory(const std::string& attribute) {
    quickSort(items_, 0, items_.size() - 1, attribute);
}

void Inventory::quickSort(std::vector<Item*>& items, int low, int high, const std::string& attribute) {
    if (low < high) {
        int pi = partition(items, low, high, attribute);

        quickSort(items, low, pi - 1, attribute);
        quickSort(items, pi + 1, high, attribute);
    }
}

int Inventory::partition(std::vector<Item*>& items, int low, int high, const std::string& attribute) {
    Item* pivot = items[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (attribute == "id" && items[j]->getId() < pivot->getId()) {
            i++;
            std::swap(items[i], items[j]);
        } else if (attribute == "name" && items[j]->getName() < pivot->getName()) {
            i++;
            std::swap(items[i], items[j]);
        } else if (attribute == "price" && items[j]->getPrice() < pivot->getPrice()) {
            i++;
            std::swap(items[i], items[j]);
        } else if (attribute == "quantity" && items[j]->getQuantity() < pivot->getQuantity()) {
            i++;
            std::swap(items[i], items[j]);
        }
    }
    std::swap(items[i + 1], items[high]);
    return (i + 1);
}
