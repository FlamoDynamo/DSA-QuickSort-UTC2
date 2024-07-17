#include "Utilities.h"
#include <limits>

void clearCin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntegerInput(const std::string& prompt) {
    int input;
    while (!(std::cin >> input)) {
        std::cout << prompt << std::endl;
        clearCin();
    }
    clearCin();
    return input;
}

double getDoubleInput(const std::string& prompt) {
    double input;
    while (!(std::cin >> input)) {
        std::cout << prompt << std::endl;
        clearCin();
    }
    clearCin();
    return input;
}

std::string getStringInput(const std::string& prompt) {
    std::string input;
    std::getline(std::cin, input);
    return input;
}
