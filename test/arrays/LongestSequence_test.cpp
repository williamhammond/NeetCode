#include "arrays/LongestSequence.h"

#include <gtest/gtest.h>

#include <vector>

TEST(LongestSequence, solves) {
  std::vector<int> input = {100, 4, 200, 1, 3, 2};
  int result = LongestSequence::solve(input);
  EXPECT_EQ(4, result);  // {1, 2, 3, 4}
}

TEST(LongestSequence, empty) {
  std::vector<int> input = {};
  int result = LongestSequence::solve(input);
  EXPECT_EQ(0, result);
}

TEST(LongestSequence, handles_negative) {
  std::vector<int> input = {0, -1, 2, 1, -2, 30};
  int result = LongestSequence::solve(input);
  EXPECT_EQ(5, result);
}
