#include <gtest/gtest.h>
#include "../../src/arrays/public/TopKFrequentElements.h"

TEST(TopKFrequentElements, solves) {
    std::vector<int> input = {1, 2, 3};
    auto actual = TopKFrequentElements::solve(input, 1);

    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";
}
