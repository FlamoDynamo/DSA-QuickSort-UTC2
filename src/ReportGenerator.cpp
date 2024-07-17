#include "ReportGenerator.h"
#include <sstream>

std::string ReportGenerator::generateInventoryReport(const Inventory& inventory) {
    std::stringstream report;
    report << "Inventory Report:\n";
    report << "--------------------\n";
    for (Item* item : inventory.getItems()) {
        report << "Name: " << item->getName() << "\n";
        report << "ID: " << item->getId() << "\n";
        report << "Price: " << item->getPrice() << "\n";
        report << "Quantity: " << item->getQuantity() << "\n";
        report << "--------------------\n";
    }
    return report.str();
}

std::string ReportGenerator::generateLowStockReport(const Inventory& inventory) {
    std::stringstream report;
    report << "Low Stock Report:\n";
    report << "--------------------\n";
    for (Item* item : inventory.getItems()) {
        if (item->getQuantity() <= 5) {
            report << "Name: " << item->getName() << "\n";
            report << "ID: " << item->getId() << "\n";
            report << "Quantity: " << item->getQuantity() << "\n";
            report << "--------------------\n";
        }
    }
    return report.str();
}

std::string ReportGenerator::generateAttributeReport(const Inventory& inventory, const std::string& attribute) {
    std::stringstream report;
    report << "Attribute Report (" << attribute << "):\n";
    report << "--------------------\n";
    for (Item* item : inventory.getItems()) {
        if (attribute == "id") {
            report << "ID: " << item->getId() << "\n";
        } else if (attribute == "name") {
            report << "Name: " << item->getName() << "\n";
        } else if (attribute == "price") {
            report << "Price: " << item->getPrice() << "\n";
        } else if (attribute == "quantity") {
            report << "Quantity: " << item->getQuantity() << "\n";
        }
        report << "--------------------\n";
    }
    return report.str();
}
