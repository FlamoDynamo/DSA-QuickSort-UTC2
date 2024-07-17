#include <iostream>
#include "Database.h"
#include "UI.h"

int main() {
    Database database;

    // Load inventory data from file
    database.loadInventory("data/items.txt");

    // Initialize and run the UI
    UI ui;
    ui.showMainMenu(database.getInventory());

    // Save inventory data to file
    database.saveInventory("data/items.txt");

    return 0;
}
