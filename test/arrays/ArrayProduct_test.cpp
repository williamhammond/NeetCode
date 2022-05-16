#include "arrays/ArrayProduct.h"

#include <gtest/gtest.h>

#include <vector>

TEST(ArrayProduct, solves) {
  std::vector<int> input = {1, 2, 3};
  auto actual = ArrayProduct::solve(input);
  std::vector<int> expected = {6, 3, 2};
  EXPECT_EQ(expected, actual);

  input = {1, 2, 3, 4};
  actual = ArrayProduct::solve(input);
  expected = {24, 12, 8, 6};
  EXPECT_EQ(expected, actual);

  input = {-1, 1, 0, -3, 3};
  actual = ArrayProduct::solve(input);
  expected = {0, 0, 9, 0, 0};
  EXPECT_EQ(expected, actual);

  input = {1, 1, 1, 1};
  actual = ArrayProduct::solve(input);
  expected = {1, 1, 1, 1};
  EXPECT_EQ(expected, actual);
}
