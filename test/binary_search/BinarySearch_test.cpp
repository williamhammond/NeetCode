#include "binary_search/BinarySearch.h"

#include <gtest/gtest.h>

#include <vector>

struct SearchTest {
  std::vector<int> nums;
  int target;
  int expected;
};
TEST(BinarySearch, it_solves_search) {
  std::vector<SearchTest> tests = {
      {{1, 2, 3}, 2, 1},    {{1, 2, 3, 4}, 4, 3}, {{-1, 0, 1}, 0, 1},
      {{-1, 0, 1}, 10, -1}, {{5}, -5, -1},
  };
  for (auto test : tests) {
    auto actual = BinarySearch::search(test.nums, test.target);
    EXPECT_EQ(test.expected, actual);
  }
}