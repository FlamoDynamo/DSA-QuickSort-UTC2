#include "utils.h"
#include <cctype> // For toupper and tolower

std::string toUpper(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(c);
    }
    return result;
}

std::string toLower(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

bool isValidSKU(const std::string& sku) {
    // You can customize this validation based on your SKU requirements
    if (sku.empty()) {
        return false; // SKU cannot be empty
    }
    for (char c : sku) {
        if (!std::isalnum(c)) {
            return false; // SKU must be alphanumeric
        }
    }
    return true;
}

bool isValidPrice(const std::string& priceStr) {
    // You can customize this validation based on your price requirements
    try {
        double price = std::stod(priceStr);
        return price >= 0.0; // Price must be non-negative
    } catch (const std::exception& e) {
        return false; // Invalid price format
    }
}

bool isValidQuantity(const std::string& quantityStr) {
    // You can customize this validation based on your quantity requirements
    try {
        int quantity = std::stoi(quantityStr);
        return quantity >= 0; // Quantity must be non-negative
    } catch (const std::exception& e) {
        return false; // Invalid quantity format
    }
}