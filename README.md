# DSA-QuickSort-UTC2

# Inventory Management System

This project implements a simple inventory management system using C++.

## Features

* **Item Management:**
    * Add new items to the inventory.
    * Remove existing items from the inventory.
    * Update the quantity of an item.
    * Find an item by its ID.
* **Inventory Sorting:**
    * Sort the inventory by ID, name, price, or quantity.
* **Database:**
    * Load inventory data from a text file.
    * Save inventory data to a text file.
* **Reporting:**
    * Generate a full inventory report.
    * Generate a low stock report.
    * Generate a report sorted by a specific attribute.
* **User Interface:**
    * A simple text-based user interface.

## Usage

1. **Build the project:**
   ```bash
   cmake .
   make
   ```
Run the executable:
   ```bash
   ./bin/InventoryManagementSystem
   ```

# Documentation
## Item Class
The Item class represents a single item in the inventory. It stores the following information:

* **Name**: The name of the item.
* **ID**: A unique identifier for the item.
* **Price**: The price of the item.
* **Quantity**: The current quantity of the item in stock.

### Methods
* **getName()**: Returns the name of the item.
* **getId()**: Returns the ID of the item.
* **getPrice()**: Returns the price of the item.
* **getQuantity()**: Returns the quantity of the item.
* **setName(const std::string& name)**: Sets the name of the item.
* **setPrice(double price)**: Sets the price of the item.
* **setQuantity(int quantity)**: Sets the quantity of the item.

### Example
```c
Item item("Laptop", 1, 1200, 10);

std::cout << "Name: " << item.getName() << std::endl;
std::cout << "ID: " << item.getId() << std::endl;
std::cout << "Price: " << item.getPrice() << std::endl;
std::cout << "Quantity: " << item.getQuantity() << std::endl;
```

## Inventory Class
The Inventory class manages the collection of items in the inventory. It provides methods for adding, removing, updating, finding, and sorting items.

### Methods
* **addItem(const Item& item)**: Adds a new item to the inventory.
* **removeItem(int id)**: Removes the item with the given ID from the inventory.
* **updateItemQuantity(int id, int newQuantity)**: Updates the quantity of the item with the given ID.
* **findItem(int id)**: Finds the item with the given ID and returns a pointer to it. If the item is not found, it returns nullptr.
* **getItems()**: Returns a vector of pointers to all items in the inventory.
* **sortInventory(const std::string& attribute)**: Sorts the inventory based on the given attribute (ID, name, price, or quantity).

### Example
```c
Inventory inventory;

// Add items
inventory.addItem(Item("Laptop", 1, 1200, 10));
inventory.addItem(Item("Keyboard", 2, 50, 20));

// Remove an item
inventory.removeItem(1);

// Update the quantity of an item
inventory.updateItemQuantity(2, 15);

// Find an item
Item* keyboard = inventory.findItem(2);

// Sort the inventory by name
inventory.sortInventory("name");
```

## Database Class
The Database class handles the loading and saving of inventory data from/to a text file.

### Methods
* **loadInventory(const std::string& filename)**: Loads inventory data from the specified text file.
* **saveInventory(const std::string& filename)**: Saves the current inventory data to the specified text file.

### Example
```c
Database database;

// Load inventory from a file
database.loadInventory("data/items.txt");

// Get the inventory
Inventory inventory = database.getInventory();

// ... modify the inventory ...

// Save the inventory to a file
database.saveInventory("data/updated_items.txt");
```

## ReportGenerator Class
The ReportGenerator class generates various reports based on the inventory data.

### Methods
* **generateInventoryReport(const Inventory& inventory)**: Generates a full inventory report.
* **generateLowStockReport(const Inventory& inventory)**: Generates a report of items with low stock.
* **generateAttributeReport(const Inventory& inventory, const std::string& attribute)**: Generates a report sorted by the specified attribute.

### Example
```c
ReportGenerator reportGenerator;

// Generate a full inventory report
std::string inventoryReport = reportGenerator.generateInventoryReport(inventory);

// Generate a low stock report
std::string lowStockReport = reportGenerator.generateLowStockReport(inventory);

// Generate a report sorted by price
std::string priceReport = reportGenerator.generateAttributeReport(inventory, "price");
```

## UI Class
The UI class provides a simple text-based user interface for interacting with the inventory management system.

### Methods
* **displayMenu()**: Displays the main menu to the user.
* **getInput()**: Prompts the user for input and returns the entered value.
* **displayMessage(const std::string& message)**: Displays a message to the user.
* **displayInventory(const Inventory& inventory)**: Displays the current inventory to the user.
* **displayReport(const std::string& report)**: Displays a generated report to the user.
* **runLoop(Inventory& inventory, Database& database, ReportGenerator& reportGenerator)**: The main loop that handles user interaction and calls the appropriate functions.

### Example
```c
UI ui;

// Run the UI loop
ui.runLoop(inventory, database, reportGenerator);
```
