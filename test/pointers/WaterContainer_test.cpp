#include "pointers/WaterContainer.h"
#include <gtest/gtest.h>

TEST(WaterContainer, it_solves) {
    std::vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto actual = WaterContainer::solve(input);
    auto expected = 49;
    EXPECT_EQ(expected, actual);
}

TEST(WaterContainer, it_solves_ones) {
    std::vector<int> input = {1, 1};
    auto actual = WaterContainer::solve(input);
    auto expected = 1;
    EXPECT_EQ(expected, actual);
}
