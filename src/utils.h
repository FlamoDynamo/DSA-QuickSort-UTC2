#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>

// Function to validate SKU format
bool isValidSKU(const std::string& sku);

// Function to validate price format
bool isValidPrice(const std::string& price);

// Function to validate quantity format
bool isValidQuantity(const std::string& quantity);

// Function to validate password format
bool isValidPassword(const std::string& password);

#endif // UTILS_H