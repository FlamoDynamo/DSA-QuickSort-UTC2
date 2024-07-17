#include "UI.h"
#include <iostream>
#include "Utilities.h"
#include "ReportGenerator.h"

void UI::showMainMenu(Inventory& inventory) {
    int choice;
    do {
        std::cout << "\nInventory Management System\n";
        std::cout << "-------------------------\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Update Item Quantity\n";
        std::cout << "4. Search Item\n";
        std::cout << "5. Display Inventory Report\n";
        std::cout << "6. Display Low Stock Report\n";
        std::cout << "7. Display Attribute Report\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        choice = getIntegerInput("Invalid input. Please enter a number between 1 and 8: ");

        switch (choice) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                removeItem(inventory);
                break;
            case 3:
                updateItemQuantity(inventory);
                break;
            case 4:
                searchItem(inventory);
                break;
            case 5:
                displayInventoryReport(inventory);
                break;
            case 6:
                displayLowStockReport(inventory);
                break;
            case 7:
                displayAttributeReport(inventory);
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
}

void UI::addItem(Inventory& inventory) {
    std::string name = getStringInput("Enter item name: ");
    int id = getIntegerInput("Enter item ID: ");
    double price = getDoubleInput("Enter item price: ");
    int quantity = getIntegerInput("Enter item quantity: ");

    inventory.addItem(Item(name, id, price, quantity));
    std::cout << "Item added successfully!\n";
}

void UI::removeItem(Inventory& inventory) {
    int id = getIntegerInput("Enter item ID to remove: ");

    inventory.removeItem(id);
    std::cout << "Item removed successfully!\n";
}

void UI::updateItemQuantity(Inventory& inventory) {
    int id = getIntegerInput("Enter item ID to update: ");
    int newQuantity = getIntegerInput("Enter new quantity: ");

    inventory.updateItemQuantity(id, newQuantity);
    std::cout << "Item quantity updated successfully!\n";
}

void UI::searchItem(const Inventory& inventory) {
    int id = getIntegerInput("Enter item ID to search: ");

    Item* item = inventory.findItem(id);
    if (item != nullptr) {
        std::cout << "Item found:\n";
        std::cout << "Name: " << item->getName() << "\n";
        std::cout << "ID: " << item->getId() << "\n";
        std::cout << "Price: " << item->getPrice() << "\n";
        std::cout << "Quantity: " << item->getQuantity() << "\n";
    } else {
        std::cout << "Item not found.\n";
    }
}

void UI::displayInventoryReport(const Inventory& inventory) {
    ReportGenerator reportGenerator;
    std::cout << reportGenerator.generateInventoryReport(inventory) << std::endl;
}

void UI::displayLowStockReport(const Inventory& inventory) {
    ReportGenerator reportGenerator;
    std::cout << reportGenerator.generateLowStockReport(inventory) << std::endl;
}

void UI::displayAttributeReport(const Inventory& inventory) {
    std::string attribute;
    std::cout << "Enter attribute to sort by (id, name, price, quantity): ";
    std::getline(std::cin, attribute);

    inventory.sortInventory(attribute);

    ReportGenerator reportGenerator;
    std::cout << reportGenerator.generateAttributeReport(inventory, attribute) << std::endl;
}
