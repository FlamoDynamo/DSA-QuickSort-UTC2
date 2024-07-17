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
   ```
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
* **getName()*: Returns the name of the item.
* **getId()**: Returns the ID of the item.
* **getPrice()**: Returns the price of the item.
* **getQuantity()**: Returns the quantity of the item.
* **setName(const std::string& name)**: Sets the name of the item.
* **setPrice(double price)**: Sets the price of the item.
* **setQuantity(int quantity)**: Sets the quantity of the item.
