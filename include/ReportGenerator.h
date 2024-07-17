#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include "Inventory.h"

class ReportGenerator {
public:
    // Generate a report of all items in the inventory
    std::string generateInventoryReport(const Inventory& inventory);

    // Generate a report of items with low stock
    std::string generateLowStockReport(const Inventory& inventory);

    // Generate a report of items by a specific attribute
    std::string generateAttributeReport(const Inventory& inventory, const std::string& attribute);
};

#endif // REPORTGENERATOR_H
