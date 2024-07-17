#include "Item.h"

Item::Item(const std::string& sku, const std::string& name, const std::string& brand,
         const std::string& category, double price, int quantity, const std::string& supplier)
    : sku(sku), name(name), brand(brand), category(category), price(price), quantity(quantity), supplier(supplier) {}

std::string Item::getSKU() const {
    return sku;
}

std::string Item::getName() const {
    return name;
}

std::string Item::getBrand() const {
    return brand;
}

std::string Item::getCategory() const {
    return category;
}

double Item::getPrice() const {
    return price;
}

int Item::getQuantity() const {
    return quantity;
}

std::string Item::getSupplier() const {
    return supplier;
}

void Item::setQuantity(int newQuantity) {
    quantity = newQuantity;
}