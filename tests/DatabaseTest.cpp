#include "gtest/gtest.h"
#include "Database.h"
#include "Item.h"
#include <fstream>
#include <sstream>

TEST(DatabaseTest, LoadInventory) {
    Database database;
    database.loadInventory("data/items.txt");

    ASSERT_EQ(database.getInventory().getItems().size(), 32);
    Item* laptop = database.getInventory().findItem(1);
    ASSERT_NE(laptop, nullptr);
    ASSERT_EQ(laptop->getName(), "Laptop");
    ASSERT_EQ(laptop->getQuantity(), 10);
}

TEST(DatabaseTest, SaveInventory) {
    Database database;
    database.getInventory().addItem(Item("New Item", 33, 100, 20));

    database.saveInventory("data/test_items.txt");

    std::ifstream file("data/test_items.txt");
    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);
    std::string name, idStr, priceStr, quantityStr;
    std::getline(ss, name, ',');
    std::getline(ss, idStr, ',');
    std::getline(ss, priceStr, ',');
    std::getline(ss, quantityStr, ',');

    ASSERT_EQ(name, "New Item");
    ASSERT_EQ(std::stoi(idStr), 33);
    ASSERT_EQ(std::stod(priceStr), 100);
    ASSERT_EQ(std::stoi(quantityStr), 20);

    file.close();
}
