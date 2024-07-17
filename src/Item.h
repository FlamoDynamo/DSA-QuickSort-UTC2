#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    // Constructor
    Item(const std::string& sku, const std::string& name, const std::string& brand,
         const std::string& category, double price, int quantity, const std::string& supplier);

    // Getters
    std::string getSKU() const;
    std::string getName() const;
    std::string getBrand() const;
    std::string getCategory() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getSupplier() const;

    // Setters
    void setQuantity(int newQuantity);

private:
    std::string sku;
    std::string name;
    std::string brand;
    std::string category;
    double price;
    int quantity;
    std::string supplier;
};

#endif // ITEM_H