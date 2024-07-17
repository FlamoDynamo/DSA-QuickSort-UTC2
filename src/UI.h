#ifndef UI_H
#define UI_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "User.h"
#include "ReportGenerator.h"
#include "utils.h"

class UI {
public:
    // Constructor
    UI(Inventory& inventory, User& user, ReportGenerator& reportGenerator);

    // Methods for displaying menus and handling user input
    void displayMainMenu();
    void displayInventoryMenu();
    void displayReportMenu();
    void displayUserMenu();

    void addItem(Inventory &inventory);

    void updateItem(Inventory &inventory);

    void deleteItem(Inventory &inventory);

    void viewItem(Inventory &inventory);

    void generateInventoryReport(ReportGenerator &reportGenerator, Inventory &inventory);

    void generateLowStockReport(ReportGenerator &reportGenerator, Inventory &inventory);

    void generateCategoryReport(ReportGenerator &reportGenerator, Inventory &inventory);

    void generateSupplierReport(ReportGenerator &reportGenerator, Inventory &inventory);

    void changePassword(User &user);

    // Methods for handling specific operations
    void addItem(Inventory* inventory);
    void updateItem(Inventory* inventory);
    void deleteItem(Inventory* inventory);
    void viewItem(Inventory* inventory);
    void generateInventoryReport(ReportGenerator* reportGenerator, Inventory* inventory);
    void generateLowStockReport(ReportGenerator* reportGenerator, Inventory* inventory);
    void generateCategoryReport(ReportGenerator* reportGenerator, Inventory* inventory);
    void generateSupplierReport(ReportGenerator* reportGenerator, Inventory* inventory);
    void changePassword(User* user);
    void logout();

private:
    Inventory& inventory; // Pass Inventory as a reference
    User& user; // Pass User as a reference
    ReportGenerator& reportGenerator; // Pass ReportGenerator as a reference
};

#endif // UI_H