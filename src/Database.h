#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <fstream>
#include <vector>
#include "Item.h"

class Database {
public:
    // Constructor
    Database();

    // Methods for loading and saving inventory data
    void loadInventory(const std::string& filename, std::vector<Item*>& items);
    void saveInventory(const std::string& filename, const std::vector<Item*>& items);
};

#endif // DATABASE_H