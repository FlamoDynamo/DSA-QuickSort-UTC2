#include "Item.h"

Item::Item(int id, const std::string& name, const std::string& description, int quantity, double unitPrice)
    : id_(id), name_(name), description_(description), quantity_(quantity), unitPrice_(unitPrice) {}

// Getters
int Item::getId() const { return id_; }
std::string Item::getName() const { return name_; }
std::string Item::getDescription() const { return description_; }
int Item::getQuantity() const { return quantity_; }
double Item::getUnitPrice() const { return unitPrice_; }

// Setters
void Item::setName(const std::string& name) { name_ = name; }
void Item::setDescription(const std::string& description) { description_ = description; }
void Item::setQuantity(int quantity) { quantity_ = quantity; }
void Item::setUnitPrice(double unitPrice) { unitPrice_ = unitPrice; }
