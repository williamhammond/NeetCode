#include <gtest/gtest.h>
#include <sliding_window/SlidingWindow.h>

#include <string>
#include <vector>

TEST(SlidingWindow, it_solves_max_profit) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  int expected = 5;
  int actual = SlidingWindow::max_profit(prices);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_max_profit_with_no_gains) {
  std::vector<int> prices = {7, 6, 4, 3, 1};
  int expected = 0;
  int actual = SlidingWindow::max_profit(prices);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_max_profit_with_mountain_pattern) {
  std::vector<int> prices = {1, 2, 1000, 2, 1};
  int expected = 999;
  int actual = SlidingWindow::max_profit(prices);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_longest_substring) {
  std::string input = "abcabcbb";
  int expected = 3;  // "abc"
  int actual = SlidingWindow::length_of_longest_substring(input);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_longest_substring_with_empty_string) {
  std::string input = "";
  int expected = 0;
  int actual = SlidingWindow::length_of_longest_substring(input);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_longest_substring_with_single_char) {
  std::string input = "a";
  int expected = 1;
  int actual = SlidingWindow::length_of_longest_substring(input);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow,
     it_solves_longest_substring_with_single_repeating_character) {
  std::string input = "bbbb";
  int expected = 1;
  int actual = SlidingWindow::length_of_longest_substring(input);
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_character_replacement) {
  int actual = SlidingWindow::characterReplacement("ABAB", 2);
  int expected = 4;
  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_check_inclusion) {
  auto actual = SlidingWindow::check_inclusion("ab", "eidbaoooo");
  EXPECT_EQ(true, actual);

  actual = SlidingWindow::check_inclusion("ab", "eidbooaoo");
  EXPECT_EQ(false, actual);
}

TEST(SlidingWindow, it_solves_min_window) {
  std::string actual = SlidingWindow::min_window("ADOBECODEBANC", "ABC");
  std::string expected = "BANC";

  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_min_window_identical) {
  std::string actual = SlidingWindow::min_window("a", "a");
  std::string expected = "a";

  EXPECT_EQ(expected, actual);
}

TEST(SlidingWindow, it_solves_min_window_when_t_is_larger) {
  std::string actual = SlidingWindow::min_window("a", "aa");
  std::string expected = "";

  EXPECT_EQ(expected, actual);
}

/**
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * 1 [3  -1  -3] 5  3  6  7       3
 * 1  3 [-1  -3  5] 3  6  7       5
 * 1  3  -1 [-3  5  3] 6  7       5
 * 1  3  -1  -3 [5  3  6] 7       6
 * 1  3  -1  -3  5 [3  6  7]      7
 */
TEST(SlidingWindow, it_solves_max_sliding_window) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<int> actual = SlidingWindow::max_sliding_window(nums, 3);
  std::vector<int> expected = {3, 3, 5, 5, 6, 7};

  EXPECT_EQ(expected, actual);
}
