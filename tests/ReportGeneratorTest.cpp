#include "gtest/gtest.h"
#include "ReportGenerator.h"
#include "Inventory.h"
#include "Item.h"

TEST(ReportGeneratorTest, GenerateInventoryReport) {
    Inventory inventory;
    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 20));

    ReportGenerator reportGenerator;
    std::string report = reportGenerator.generateInventoryReport(inventory);

    ASSERT_NE(report.find("Laptop"), std::string::npos);
    ASSERT_NE(report.find("Keyboard"), std::string::npos);
    ASSERT_NE(report.find("ID: 1"), std::string::npos);
    ASSERT_NE(report.find("ID: 2"), std::string::npos);
}

TEST(ReportGeneratorTest, GenerateLowStockReport) {
    Inventory inventory;
    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 2));

    ReportGenerator reportGenerator;
    std::string report = reportGenerator.generateLowStockReport(inventory);

    ASSERT_NE(report.find("Keyboard"), std::string::npos);
    ASSERT_EQ(report.find("Laptop"), std::string::npos);
}

TEST(ReportGeneratorTest, GenerateAttributeReport) {
    Inventory inventory;
    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 20));

    ReportGenerator reportGenerator;
    std::string report = reportGenerator.generateAttributeReport(inventory, "name");

    ASSERT_NE(report.find("Laptop"), std::string::npos);
    ASSERT_NE(report.find("Keyboard"), std::string::npos);
    ASSERT_EQ(report.find("ID: 1"), std::string::npos);
    ASSERT_EQ(report.find("ID: 2"), std::string::npos);
}
