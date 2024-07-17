#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Item {
public:
    Item(const std::string& sku, const std::string& name, const std::string& brand, const std::string& category, double price, int quantity, const std::string& supplier);

    // Getters
    std::string getSKU() const;
    std::string getName() const;
    std::string getBrand() const;
    std::string getCategory() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getSupplier() const;

private:
    std::string sku;
    std::string name;
    std::string brand;
    std::string category;
    double price;
    int quantity;
    std::string supplier;
};

class Inventory {
public:
    // Constructor
    Inventory();

    // Methods for managing items
    void addItem(const std::string& sku, const std::string& name, const std::string& brand, const std::string& category, double price, int quantity, const std::string& supplier);
    bool itemExists(const std::string& sku) const;
    void updateItem(const std::string& sku, const std::string& name, const std::string& brand, const std::string& category, double price, int quantity, const std::string& supplier);
    void deleteItem(const std::string& sku);
    Item* getItem(const std::string& sku) const;
    std::vector<Item*> getItems() const;

private:
    std::vector<Item*> items; 
};

#endif // INVENTORY_H