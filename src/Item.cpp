#include "Item.h"

Item::Item(const std::string& name, int id, double price, int quantity) :
    name_(name), id_(id), price_(price), quantity_(quantity) {}

std::string Item::getName() const {
    return name_;
}

int Item::getId() const {
    return id_;
}

double Item::getPrice() const {
    return price_;
}

int Item::getQuantity() const {
    return quantity_;
}

void Item::setName(const std::string& name) {
    name_ = name;
}

void Item::setPrice(double price) {
    price_ = price;
}

void Item::setQuantity(int quantity) {
    quantity_ = quantity;
}
