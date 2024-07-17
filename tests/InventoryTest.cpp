#include "gtest/gtest.h"
#include "Inventory.h"
#include "Item.h"

TEST(InventoryTest, AddItem) {
    Inventory inventory;

    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 20));

    ASSERT_EQ(inventory.getItems().size(), 2);
}

TEST(InventoryTest, RemoveItem) {
    Inventory inventory;

    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 20));

    inventory.removeItem(1);

    ASSERT_EQ(inventory.getItems().size(), 1);
    ASSERT_EQ(inventory.findItem(1), nullptr);
}

TEST(InventoryTest, UpdateItemQuantity) {
    Inventory inventory;

    inventory.addItem(Item("Laptop", 1, 1200, 10));

    inventory.updateItemQuantity(1, 5);

    Item* laptop = inventory.findItem(1);
    ASSERT_NE(laptop, nullptr);
    ASSERT_EQ(laptop->getQuantity(), 5);
}

TEST(InventoryTest, FindItem) {
    Inventory inventory;

    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Keyboard", 2, 50, 20));

    Item* laptop = inventory.findItem(1);
    ASSERT_NE(laptop, nullptr);
    ASSERT_EQ(laptop->getId(), 1);

    Item* mouse = inventory.findItem(3);
    ASSERT_EQ(mouse, nullptr);
}

TEST(InventoryTest, SortInventory) {
    Inventory inventory;

    inventory.addItem(Item("Keyboard", 2, 50, 20));
    inventory.addItem(Item("Laptop", 1, 1200, 10));
    inventory.addItem(Item("Mouse", 3, 25, 30));

    inventory.sortInventory("id");

    std::vector<Item*> sortedItems = inventory.getItems();
    ASSERT_EQ(sortedItems[0]->getId(), 1);
    ASSERT_EQ(sortedItems[1]->getId(), 2);
    ASSERT_EQ(sortedItems[2]->getId(), 3);
}
