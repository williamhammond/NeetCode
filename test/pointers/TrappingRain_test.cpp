#include <gtest/gtest.h>
#include <pointers/TrappingRain.h>

TEST(TrappingRain, it_solves) {
  std::vector<std::size_t> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto result = TrappingRain::solve(input);
  EXPECT_EQ(6, result);
}

TEST(TrappingRain, it_handles_monotonic_increase) {
  std::vector<std::size_t> input = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  auto result = TrappingRain::solve(input);
  EXPECT_EQ(0, result);
}

TEST(TrappingRain, it_handles_monotonic_decrease) {
  std::vector<std::size_t> input = {8, 7, 6, 5, 4, 3, 2, 1, 0};
  auto result = TrappingRain::solve(input);
  EXPECT_EQ(0, result);
}

TEST(TrappingRain, it_solves_canyon) {
  std::vector<std::size_t> input = {3, 2, 1, 0, 1, 2, 3};
  auto result = TrappingRain::solve(input);
  EXPECT_EQ(9, result);
}
