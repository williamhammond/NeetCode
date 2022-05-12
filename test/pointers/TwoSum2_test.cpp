#include <gtest/gtest.h>
#include "../../src/pointers/public/TwoSum2.h"
#include <vector>

TEST(TwoSum, it_solves_simple) {
    std::vector<int> input = {2, 7, 11, 15};
    std::vector<std::size_t> result = TwoSum2::solve(input, 9);
    std::vector<std::size_t> expected = {1, 2};
    EXPECT_EQ(expected, result);
}

TEST(TwoSum, it_solves_short) {
    std::vector<int> input = {1, 2};
    std::vector<std::size_t> result = TwoSum2::solve(input, 3);
    std::vector<std::size_t> expected = {1, 2};
    EXPECT_EQ(expected, result);
}

TEST(TwoSum, it_handles_min_and_max) {
    std::vector<int> input = {-1000, 1000};
    std::vector<std::size_t> result = TwoSum2::solve(input, 0);
    std::vector<std::size_t> expected = {1, 2};
    EXPECT_EQ(expected, result);
}

TEST(TwoSum, it_solves) {
    std::vector<int> input = {-1000, -123, -1, 0, 5, 10, 11, 13, 1000};
    std::vector<std::size_t> result = TwoSum2::solve(input, 1005);
    std::vector<std::size_t> expected = {5, 9};
    EXPECT_EQ(expected, result);
}
