#include "arrays/ContainsDuplicates.h"

#include <gtest/gtest.h>

TEST(ContainsDuplicates, NoDuplicateSimple) {
  std::vector<int> input = {1, 2, 3, 4};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, false) << "Falsely found a duplicate";
}

TEST(ContainsDuplicates, SingleValue) {
  std::vector<int> input = {1};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, false) << "Falsely found a duplicate";
}

TEST(ContainsDuplicates, SingleDuplicateSimple) {
  std::vector<int> input = {1, 2, 3, 1};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, true) << "Didn't find duplicate 1";
}

TEST(ContainsDuplicates, MultipleDuplicates) {
  std::vector<int> input = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, true) << "Didn't find multiple duplicates";
}

TEST(ContainsDuplicates, EmptyVector) {
  std::vector<int> input = {};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, false) << "Didn't find multiple duplicates";
}

TEST(ContainsDuplicates, OnlyDuplicates) {
  std::vector<int> input = {1, 1, 1, 1, 1};
  bool result = ContainsDuplicates::solve(input);
  EXPECT_EQ(result, true) << "Didn't find multiple duplicates";
}
