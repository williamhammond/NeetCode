#include "arrays/TopKFrequentElements.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

TEST(TopKFrequentElements, solves) {
  std::vector<int> input = {1, 2, 3};
  auto actual = TopKFrequentElements::solve(input, 3);
  std::sort(actual.begin(), actual.end());
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";

  input = {1, 2, 2, 3, 3};
  actual = TopKFrequentElements::solve(input, 2);
  std::sort(actual.begin(), actual.end());
  expected = {2, 3};
  EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";

  input = {-1};
  actual = TopKFrequentElements::solve(input, 1);
  std::sort(actual.begin(), actual.end());
  expected = {-1};
  EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";

  input = {1, 1, 1};
  actual = TopKFrequentElements::solve(input, 1);
  std::sort(actual.begin(), actual.end());
  expected = {1};
  EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";
}
