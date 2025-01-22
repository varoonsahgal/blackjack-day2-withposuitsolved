#include <gtest/gtest.h>
#include "card.h"  // Include the header for your Card class

// Test default constructor
TEST(CardTest, DefaultConstructor) {
    Card card;
    EXPECT_EQ(card.getNumber(), 1);        // Default number should be 0
    EXPECT_EQ(card.getSuit(), '\0');      // Default suit should be '\0'
    EXPECT_FALSE(card.getBlock());        // Default block should be false
}

// Example test case
TEST(ExampleTest, BasicAssertions) {
    // Expect equality
    EXPECT_EQ(1 + 1, 2);
    // Expect inequality
    EXPECT_EQ(2 * 2, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
