#include <gtest/gtest.h>
#include "arrays/TwoSum.h"

TEST(TwoSum, ItFindsSum) {
    std::vector<int> input = {2, 7, 11, 15};
    auto result = TwoSum2::solve(input, 9);
    std::vector<std::size_t> expected = {0, 1};
    EXPECT_EQ(expected, result) << "Incorrect result for two sum";

    input = {0, 0};
    expected = {0, 1};
    result = TwoSum2::solve(input, 0);
    EXPECT_EQ(expected, result) << "Incorrect result for two sum";

    input = {1, -1};
    expected = {0, 1};
    result = TwoSum2::solve(input, 0);
    EXPECT_EQ(expected, result) << "Incorrect result for two sum";
}
