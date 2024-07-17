#include <iostream>
#include "Inventory.h"
#include "User.h"
#include "ReportGenerator.h"
#include "UI.h"

int main() {
    // Initialize Inventory, User, and ReportGenerator
    Inventory inventory;
    User user("admin", "password"); // Example user
    ReportGenerator reportGenerator;

    // Create UI instance
    UI ui(inventory, user, reportGenerator);

    // Main loop
    bool running = true;
    while (running) {
        ui.displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: { // Inventory
                ui.displayInventoryMenu();
                int inventoryChoice;
                std::cin >> inventoryChoice;

                switch (inventoryChoice) {
                    case 1: ui.addItem(inventory); break;
                    case 2: ui.updateItem(inventory); break;
                    case 3: ui.deleteItem(inventory); break;
                    case 4: ui.viewItem(inventory); break;
                    case 5: break; // Back to main menu
                    default: std::cout << "Invalid choice.\n";
                }
                break;
            }
            case 2: { // Reports
                ui.displayReportMenu();
                int reportChoice;
                std::cin >> reportChoice;

                switch (reportChoice) {
                    case 1: ui.generateInventoryReport(reportGenerator, inventory); break;
                    case 2: ui.generateLowStockReport(reportGenerator, inventory); break;
                    case 3: ui.generateCategoryReport(reportGenerator, inventory); break;
                    case 4: ui.generateSupplierReport(reportGenerator, inventory); break;
                    case 5: break; // Back to main menu
                    default: std::cout << "Invalid choice.\n";
                }
                break;
            }
            case 3: { // User
                ui.displayUserMenu();
                int userChoice;
                std::cin >> userChoice;

                switch (userChoice) {
                    case 1: ui.changePassword(user); break;
                    case 2: break; // Back to main menu
                    default: std::cout << "Invalid choice.\n";
                }
                break;
            }
            case 4: { // Logout
                ui.logout();
                running = false;
                break;
            }
            default: std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}