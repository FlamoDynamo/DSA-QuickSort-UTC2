#include "Utilities.h"
#include <limits> // For numeric_limits

namespace Utilities {

    int getValidIntInput(const std::string& prompt) {
        int input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return input;
            } else {
                std::cout << "Invalid input. Please enter an integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    double getValidDoubleInput(const std::string& prompt) {
        double input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return input;
            } else {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    std::string getValidStringInput(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            if (std::getline(std::cin, input)) { // Use getline for string input
                if (input.empty()) {
                    std::cout << "Input cannot be empty.\n";
                } else {
                    return input;
                }
            } else {
                std::cout << "Invalid input.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    // Comparison Functions for Sorting
    bool compareById(const Item& a, const Item& b) {
        return a.getId() < b.getId();
    }

    bool compareByName(const Item& a, const Item& b) {
        return a.getName() < b.getName();
    }
}
