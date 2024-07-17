#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

// Function to clear the input buffer
void clearCin();

// Function to validate user input for an integer
int getIntegerInput(const std::string& prompt);

// Function to validate user input for a double
double getDoubleInput(const std::string& prompt);

// Function to validate user input for a string
std::string getStringInput(const std::string& prompt);

#endif // UTILITIES_H
