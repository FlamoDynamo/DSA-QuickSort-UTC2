#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include "Item.h"

namespace Utilities {
    // Input Validation Functions
    int getValidIntInput(const std::string& prompt);
    double getValidDoubleInput(const std::string& prompt);
    std::string getValidStringInput(const std::string& prompt);

    // Comparison Functions for Sorting (Add more as needed)
    bool compareById(const Item& a, const Item& b);
    bool compareByName(const Item& a, const Item& b);
}

#endif // UTILITIES_H
