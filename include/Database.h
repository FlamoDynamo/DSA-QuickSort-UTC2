#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "Inventory.h"

class Database {
public:
    // Load inventory data from a file
    void loadInventory(const std::string& filename);

    // Save inventory data to a file
    void saveInventory(const std::string& filename);

    // Get the current inventory
    Inventory& getInventory();

private:
    Inventory inventory_;
};

#endif // DATABASE_H
