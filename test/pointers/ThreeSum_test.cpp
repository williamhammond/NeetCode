
#include "pointers/ThreeSum.h"

#include <gtest/gtest.h>

#include <vector>

TEST(ThreeSum, it_solves_empty) {
  std::vector<int> input = {};
  std::vector<std::vector<int>> result = ThreeSum::solve(input);
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(expected, result);
}

TEST(ThreeSum, it_solves_single) {
  std::vector<int> input = {0};
  std::vector<std::vector<int>> result = ThreeSum::solve(input);
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(expected, result);
}

TEST(ThreeSum, it_solves_couple) {
  std::vector<int> input = {0, 1};
  std::vector<std::vector<int>> result = ThreeSum::solve(input);
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(expected, result);
}

TEST(ThreeSum, it_solves_simple) {
  std::vector<int> input = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> result = ThreeSum::solve(input);
  std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(expected, result);
}

TEST(ThreeSum, it_solves_zeroes) {
  std::vector<int> input = {0, 0, 0, 0};
  std::vector<std::vector<int>> result = ThreeSum::solve(input);
  std::vector<std::vector<int>> expected = {
      {0, 0, 0},
  };
  EXPECT_EQ(expected, result);
}
