#include <iostream>
#include "Inventory.h"
#include "Utilities.h"

int main() {
    Inventory inventory;
    int choice;

    do {
        std::cout << "\nInventory Management System" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Update Item" << std::endl;
        std::cout << "3. Delete Item" << std::endl;
        std::cout << "4. Find Item" << std::endl;
        std::cout << "5. Sort Inventory (by ID)" << std::endl;
        std::cout << "6. Sort Inventory (by Name)" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        choice = Utilities::getValidIntInput("");

        switch (choice) {
          case 1: { // Add Item
              int id = Utilities::getValidIntInput("Enter Item ID: ");
              std::string name = Utilities::getValidStringInput("Enter Item Name: ");
              std::string description = Utilities::getValidStringInput("Enter Description: ");
              int quantity = Utilities::getValidIntInput("Enter Quantity: ");
              double unitPrice = Utilities::getValidDoubleInput("Enter Unit Price: ");
      
              Item newItem(id, name, description, quantity, unitPrice);
              inventory.addItem(newItem);
              std::cout << "Item added successfully!\n";
              break;
          }
          case 2: { // Update Item
              int itemId = Utilities::getValidIntInput("Enter Item ID to update: ");
              Item* itemToUpdate = inventory.findItemById(itemId);
      
              if (itemToUpdate != nullptr) {
                  std::cout << "Enter new details for the item:\n";
                  std::string name = Utilities::getValidStringInput("Enter Item Name: ");
                  std::string description = Utilities::getValidStringInput("Enter Description: ");
                  int quantity = Utilities::getValidIntInput("Enter Quantity: ");
                  double unitPrice = Utilities::getValidDoubleInput("Enter Unit Price: ");
      
                  itemToUpdate->setName(name);
                  itemToUpdate->setDescription(description);
                  itemToUpdate->setQuantity(quantity);
                  itemToUpdate->setUnitPrice(unitPrice);
      
                  std::cout << "Item updated successfully!\n";
              } else {
                  std::cout << "Item not found.\n";
              }
              break;
          }
          case 3: { // Delete Item
              int itemId = Utilities::getValidIntInput("Enter Item ID to delete: ");
              inventory.deleteItem(itemId);
              std::cout << "Item deleted successfully (if found).\n";
              break;
          }
          case 4: { // Find Item
              int itemId = Utilities::getValidIntInput("Enter Item ID to find: ");
              Item* foundItem = inventory.findItemById(itemId);
              
              if (foundItem != nullptr) {
                  std::cout << "Item ID: " << foundItem->getId() << std::endl;
                  std::cout << "Name: " << foundItem->getName() << std::endl;
                  std::cout << "Description: " << foundItem->getDescription() << std::endl;
                  std::cout << "Quantity: " << foundItem->getQuantity() << std::endl;
                  std::cout << "Unit Price: $" << foundItem->getUnitPrice() << std::endl;
              } else {
                  std::cout << "Item not found.\n";
              }
              break;
          }
          case 5: // Sort by ID
              inventory.sortBy(Utilities::compareById);
              std::cout << "Inventory sorted by ID.\n";
              break;
          case 6: // Sort by Name
              inventory.sortBy(Utilities::compareByName);
              std::cout << "Inventory sorted by Name.\n";
              break;
          case 7:
              std::cout << "Exiting program...\n";
              break;
          default:
              std::cout << "Invalid choice. Please try again.\n";
      }
    } while (choice != 7);

    return 0;
}
