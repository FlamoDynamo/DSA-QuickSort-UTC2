#include "ReportGenerator.h"
#include <iostream>
#include <iomanip>

ReportGenerator::ReportGenerator() {
    // Constructor implementation (optional)
}

void ReportGenerator::generateInventoryReport(const std::vector<Item*>& items) {
    std::cout << "\nInventory Report:\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << std::setw(10) << "SKU" << std::setw(20) << "Name" << std::setw(15) << "Brand"
              << std::setw(15) << "Category" << std::setw(10) << "Price" << std::setw(10) << "Quantity"
              << std::setw(20) << "Supplier" << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    for (Item* item : items) {
        std::cout << std::setw(10) << item->getSKU() << std::setw(20) << item->getName()
                  << std::setw(15) << item->getBrand() << std::setw(15) << item->getCategory()
                  << std::setw(10) << item->getPrice() << std::setw(10) << item->getQuantity()
                  << std::setw(20) << item->getSupplier() << std::endl;
    }
    std::cout << "--------------------------------------------------------------------\n";
}

void ReportGenerator::generateLowStockReport(const std::vector<Item*>& items, int lowStockThreshold) {
    std::cout << "\nLow Stock Report:\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << std::setw(10) << "SKU" << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    for (Item* item : items) {
        if (item->getQuantity() < lowStockThreshold) {
            std::cout << std::setw(10) << item->getSKU() << std::setw(20) << item->getName()
                      << std::setw(10) << item->getQuantity() << std::endl;
        }
    }
    std::cout << "--------------------------------------------------------------------\n";
}

void ReportGenerator::generateCategoryReport(const std::vector<Item*>& items, const std::string& category) {
    std::cout << "\nCategory Report (" << category << "):\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << std::setw(10) << "SKU" << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    for (Item* item : items) {
        if (item->getCategory() == category) {
            std::cout << std::setw(10) << item->getSKU() << std::setw(20) << item->getName()
                      << std::setw(10) << item->getQuantity() << std::endl;
        }
    }
    std::cout << "--------------------------------------------------------------------\n";
}

void ReportGenerator::generateSupplierReport(const std::vector<Item*>& items, const std::string& supplier) {
    std::cout << "\nSupplier Report (" << supplier << "):\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << std::setw(10) << "SKU" << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    for (Item* item : items) {
        if (item->getSupplier() == supplier) {
            std::cout << std::setw(10) << item->getSKU() << std::setw(20) << item->getName()
                      << std::setw(10) << item->getQuantity() << std::endl;
        }
    }
    std::cout << "--------------------------------------------------------------------\n";
}