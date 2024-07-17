#include "Database.h"

Database::Database() {
    // Constructor implementation (optional)
}

void Database::loadInventory(const std::string& filename, std::vector<Item*>& items) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string sku, name, brand, category, supplier;
        double price;
        int quantity;

        while (std::getline(file, sku, ',')) {
            std::getline(file, name, ',');
            std::getline(file, brand, ',');
            std::getline(file, category, ',');
            file >> price;
            file.ignore(1, ','); // Ignore the comma
            file >> quantity;
            file.ignore(1, ','); // Ignore the comma
            std::getline(file, supplier);

            Item* newItem = new Item(sku, name, brand, category, price, quantity, supplier);
            items.push_back(newItem);
        }

        file.close();
    } else {
        // Handle file opening error (e.g., log an error message)
    }
}

void Database::saveInventory(const std::string& filename, const std::vector<Item*>& items) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (Item* item : items) {
            file << item->getSKU() << "," << item->getName() << "," << item->getBrand() << ","
                 << item->getCategory() << "," << item->getPrice() << "," << item->getQuantity() << ","
                 << item->getSupplier() << std::endl;
        }
        file.close();
    } else {
        // Handle file opening error (e.g., log an error message)
    }
}