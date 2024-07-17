#include "Database.h"
#include <fstream>
#include <sstream>

void Database::loadInventory(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, idStr, priceStr, quantityStr;
            std::getline(ss, name, ',');
            std::getline(ss, idStr, ',');
            std::getline(ss, priceStr, ',');
            std::getline(ss, quantityStr, ',');

            int id = std::stoi(idStr);
            double price = std::stod(priceStr);
            int quantity = std::stoi(quantityStr);

            inventory_.addItem(Item(name, id, price, quantity));
        }
        file.close();
    }
}

void Database::saveInventory(const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (Item* item : inventory_.getItems()) {
            file << item->getName() << ","
                 << item->getId() << ","
                 << item->getPrice() << ","
                 << item->getQuantity() << std::endl;
        }
        file.close();
    }
}

Inventory& Database::getInventory() {
    return inventory_;
}
