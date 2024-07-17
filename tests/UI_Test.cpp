#include "gtest/gtest.h"
#include "UI.h" // Assuming you have a UI class
#include "Inventory.h"
#include "Item.h"
#include "Database.h"
#include "ReportGenerator.h"
#include <sstream>

// This is a basic example and needs to be adapted to your specific UI implementation
class MockUI : public UI {
public:
    std::string lastInput;
    std::string lastOutput;

    void displayMenu() override {
        lastOutput = "Menu displayed";
    }

    std::string getInput() override {
        return lastInput;
    }

    void displayMessage(const std::string& message) override {
        lastOutput = message;
    }

    void displayInventory(const Inventory& inventory) override {
        lastOutput = "Inventory displayed";
    }

    void displayReport(const std::string& report) override {
        lastOutput = report;
    }
};

TEST(UITest, MenuDisplay) {
    MockUI ui;
    ui.displayMenu();
    ASSERT_EQ(ui.lastOutput, "Menu displayed");
}

TEST(UITest, UserInput) {
    MockUI ui;
    ui.lastInput = "1";
    ASSERT_EQ(ui.getInput(), "1");
}

TEST(UITest, DisplayMessage) {
    MockUI ui;
    ui.displayMessage("Test message");
    ASSERT_EQ(ui.lastOutput, "Test message");
}

TEST(UITest, DisplayInventory) {
    MockUI ui;
    Inventory inventory;
    inventory.addItem(Item("Laptop", 1, 1200, 10));
    ui.displayInventory(inventory);
    ASSERT_EQ(ui.lastOutput, "Inventory displayed");
}

TEST(UITest, DisplayReport) {
    MockUI ui;
    std::string report = "Test report";
    ui.displayReport(report);
    ASSERT_EQ(ui.lastOutput, report);
}

TEST(UITest, RunLoop) {
    MockUI ui;
    Inventory inventory;
    Database database;
    ReportGenerator reportGenerator;

    // Simulate user input
    ui.lastInput = "1"; // Add item
    ui.lastInput = "Laptop,1,1200,10"; // Item details
    ui.lastInput = "2"; // View inventory
    ui.lastInput = "3"; // Generate report
    ui.lastInput = "4"; // Exit

    ui.runLoop(inventory, database, reportGenerator);

    // Assertions based on your UI logic
    // For example, check if the inventory was updated,
    // reports were generated, etc.
}
