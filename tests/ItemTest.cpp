#include "gtest/gtest.h"
#include "Item.h"

TEST(ItemTest, GettersAndSetters) {
    Item item("Laptop", 1, 1200, 10);

    ASSERT_EQ(item.getName(), "Laptop");
    ASSERT_EQ(item.getId(), 1);
    ASSERT_EQ(item.getPrice(), 1200);
    ASSERT_EQ(item.getQuantity(), 10);

    item.setName("Desktop");
    item.setPrice(800);
    item.setQuantity(5);

    ASSERT_EQ(item.getName(), "Desktop");
    ASSERT_EQ(item.getId(), 1); // ID should remain unchanged
    ASSERT_EQ(item.getPrice(), 800);
    ASSERT_EQ(item.getQuantity(), 5);
}
