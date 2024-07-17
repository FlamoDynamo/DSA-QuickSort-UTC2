#include "UI.h"
#include <iostream>
#include <limits> 
#include "utils.h" // Assuming isValidPassword is in utils.h

UI::UI(Inventory& inventory, User& user, ReportGenerator& reportGenerator)
    : inventory(inventory), user(user), reportGenerator(reportGenerator) {}

void UI::displayMainMenu() {
    std::cout << "\nInventory Management System\n";
    std::cout << "---------------------------\n";
    std::cout << "Logged in as: " << user.getUsername() << std::endl; 
    std::cout << "1. Inventory\n";
    std::cout << "2. Reports\n";
    std::cout << "3. User\n";
    std::cout << "4. Logout\n";
    std::cout << "Enter your choice: ";
}

void UI::displayInventoryMenu() {
    std::cout << "\nInventory Menu\n";
    std::cout << "-----------------\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Update Item\n";
    std::cout << "3. Delete Item\n";
    std::cout << "4. View Item\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void UI::displayReportMenu() {
    std::cout << "\nReport Menu\n";
    std::cout << "-----------------\n";
    std::cout << "1. Generate Inventory Report\n";
    std::cout << "2. Generate Low Stock Report\n";
    std::cout << "3. Generate Category Report\n";
    std::cout << "4. Generate Supplier Report\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void UI::displayUserMenu() {
    std::cout << "\nUser Menu\n";
    std::cout << "-----------------\n";
    std::cout << "1. Change Password\n";
    std::cout << "2. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}

// ... Implementations of operation handling methods ...

void UI::addItem(Inventory& inventory) { // Pass Inventory as a reference
    std::string sku, name, brand, category, supplier;
    double price;
    int quantity;

    std::cout << "\nAdd Item\n";
    std::cout << "-----------------\n";

    std::cout << "Enter SKU: ";
    std::cin >> sku;
    while (!isValidSKU(sku)) {
        std::cout << "Invalid SKU format. Please enter a valid SKU: ";
        std::cin >> sku;
    }

    std::cout << "Enter Name: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, name);

    std::cout << "Enter Brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter Category: ";
    std::getline(std::cin, category);

    std::cout << "Enter Price: ";
    std::cin >> price;
    while (!isValidPrice(std::to_string(price))) {
        std::cout << "Invalid price format. Please enter a valid price: ";
        std::cin >> price;
    }

    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    while (!isValidQuantity(std::to_string(quantity))) {
        std::cout << "Invalid quantity format. Please enter a valid quantity: ";
        std::cin >> quantity;
    }

    std::cout << "Enter Supplier: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, supplier);

    inventory.addItem(sku, name, brand, category, price, quantity, supplier);
    std::cout << "Item added successfully!\n";
}

/// @brief 
/// @param inventory 
void UI::updateItem(Inventory& inventory) { // Pass Inventory as a reference
    std::string sku;
    std::cout << "\nUpdate Item\n";
    std::cout << "-----------------\n";

    std::cout << "Enter SKU of the item to update: ";
    std::cin >> sku;
    while (!isValidSKU(sku)) {
        std::cout << "Invalid SKU format. Please enter a valid SKU: ";
        std::cin >> sku;
    }

    if (!inventory.itemExists(sku)) {
        std::cout << "Item with SKU " << sku << " not found.\n";
        return;
    }

    std::string name, brand, category, supplier;
    double price;
    int quantity;

    std::cout << "Enter new Name (leave blank to keep existing): ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, name);

    std::cout << "Enter new Brand (leave blank to keep existing): ";
    std::getline(std::cin, brand);

    std::cout << "Enter new Category (leave blank to keep existing): ";
    std::getline(std::cin, category);

    std::cout << "Enter new Price (leave blank to keep existing): ";
    std::cin >> price;
    if (!isValidPrice(std::to_string(price))) {
        std::cout << "Invalid price format. Please enter a valid price: ";
        std::cin >> price;
    }

    std::cout << "Enter new Quantity (leave blank to keep existing): ";
    std::cin >> quantity;
    if (!isValidQuantity(std::to_string(quantity))) {
        std::cout << "Invalid quantity format. Please enter a valid quantity: ";
        std::cin >> quantity;
    }

    std::cout << "Enter new Supplier (leave blank to keep existing): ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, supplier);

    inventory.updateItem(sku, name, brand, category, price, quantity, supplier);
    std::cout << "Item updated successfully!\n";
}

void UI::deleteItem(Inventory& inventory) { // Pass Inventory as a reference
    std::string sku;
    std::cout << "\nDelete Item\n";
    std::cout << "-----------------\n";

    std::cout << "Enter SKU of the item to delete: ";
    std::cin >> sku;
    while (!isValidSKU(sku)) {
        std::cout << "Invalid SKU format. Please enter a valid SKU: ";
        std::cin >> sku;
    }

    if (!inventory.itemExists(sku)) {
        std::cout << "Item with SKU " << sku << " not found.\n";
        return;
    }

    inventory.deleteItem(sku);
    std::cout << "Item deleted successfully!\n";
}

void UI::viewItem(Inventory& inventory) { // Pass Inventory as a reference
    std::string sku;
    std::cout << "\nView Item\n";
    std::cout << "-----------------\n";

    std::cout << "Enter SKU of the item to view: ";
    std::cin >> sku;
    while (!isValidSKU(sku)) {
        std::cout << "Invalid SKU format. Please enter a valid SKU: ";
        std::cin >> sku;
    }

    if (!inventory.itemExists(sku)) {
        std::cout << "Item with SKU " << sku << " not found.\n";
        return;
    }

    Item* item = inventory.getItem(sku); 
    std::cout << "\nItem Details:\n";
    std::cout << "-----------------\n";
    std::cout << "SKU: " << item->getSKU() << std::endl;
    std::cout << "Name: " << item->getName() << std::endl;
    std::cout << "Brand: " << item->getBrand() << std::endl;
    std::cout << "Category: " << item->getCategory() << std::endl;
    std::cout << "Price: " << item->getPrice() << std::endl;
    std::cout << "Quantity: " << item->getQuantity() << std::endl;
    std::cout << "Supplier: " << item->getSupplier() << std::endl;
}

void UI::generateInventoryReport(ReportGenerator& reportGenerator, Inventory& inventory) { // Pass objects as references
    reportGenerator.generateInventoryReport(inventory.getItems()); 
}

void UI::generateLowStockReport(ReportGenerator& reportGenerator, Inventory& inventory) { // Pass objects as references
    int threshold;
    std::cout << "Enter low stock threshold: ";
    std::cin >> threshold;
    reportGenerator.generateLowStockReport(inventory.getItems(), threshold); 
}

void UI::generateCategoryReport(ReportGenerator& reportGenerator, Inventory& inventory) { // Pass objects as references
    std::string category;
    std::cout << "Enter category: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, category);
    reportGenerator.generateCategoryReport(inventory.getItems(), category); 
}

void UI::generateSupplierReport(ReportGenerator& reportGenerator, Inventory& inventory) { // Pass objects as references
    std::string supplier;
    std::cout << "Enter supplier: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, supplier);
    reportGenerator.generateSupplierReport(inventory.getItems(), supplier); 
}

void UI::changePassword(User& user) { // Pass User as a reference
    std::string currentPassword, newPassword, confirmPassword;

    std::cout << "\nChange Password\n";
    std::cout << "-----------------\n";

    std::cout << "Enter current password: ";
    std::cin >> currentPassword;

    // Check if current password is correct
    if (currentPassword != user.getPassword()) {
        std::cout << "Incorrect current password.\n";
        return;
    }

    std::cout << "Enter new password: ";
    std::cin >> newPassword;
    while (!isValidPassword(newPassword)) {
        std::cout << "Invalid password format. Please enter a valid password: ";
        std::cin >> newPassword;
    }

    std::cout << "Confirm new password: ";
    std::cin >> confirmPassword;
    while (confirmPassword != newPassword) {
        std::cout << "Passwords do not match. Please re-enter the new password: ";
        std::cin >> confirmPassword;
    }

    // Update the user's password
    user.setPassword(newPassword); 
    std::cout << "Password changed successfully!\n";
}

void UI::logout() {
    std::cout << "Logging out...\n";
    // You can add additional logout logic here, such as:
    // - Clearing user session data
    // - Redirecting to a login screen
    // - Closing the application
    // For simplicity, we'll just exit the program for now
    exit(0);
}