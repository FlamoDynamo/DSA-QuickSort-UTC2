#ifndef UI_H
#define UI_H

#include <string>
#include "Inventory.h"

class UI {
public:
    // Main menu of the inventory management system
    void showMainMenu(Inventory& inventory);

    // Function to add a new item to the inventory
    void addItem(Inventory& inventory);

    // Function to remove an item from the inventory
    void removeItem(Inventory& inventory);

    // Function to update the quantity of an item
    void updateItemQuantity(Inventory& inventory);

    // Function to search for an item
    void searchItem(const Inventory& inventory);

    // Function to display the inventory report
    void displayInventoryReport(const Inventory& inventory);

    // Function to display the low stock report
    void displayLowStockReport(const Inventory& inventory);

    // Function to display the attribute report
    void displayAttributeReport(const Inventory& inventory);
};

#endif // UI_H
