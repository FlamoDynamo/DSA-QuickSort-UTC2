#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <vector>
#include "Item.h"

class ReportGenerator {
public:
    // Constructor
    ReportGenerator();

    // Methods for generating reports
    void generateInventoryReport(const std::vector<Item*>& items);
    void generateLowStockReport(const std::vector<Item*>& items, int lowStockThreshold);
    void generateCategoryReport(const std::vector<Item*>& items, const std::string& category);
    void generateSupplierReport(const std::vector<Item*>& items, const std::string& supplier);
};

#endif // REPORTGENERATOR_H