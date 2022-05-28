#include <gtest/gtest.h>
#include <sliding_window/SlidingWindow.h>

#include <string>
#include <vector>

struct MaxProfit {
  std::vector<int> prices{};
  int expected{};
  std::string message{};
};
TEST(SlidingWindow, it_solves_max_profit) {
  std::vector<MaxProfit> tests{MaxProfit{{7, 1, 5, 3, 6, 4}, 5, ""},
                               MaxProfit{{7, 6, 4, 3, 1}, 0, ""},
                               MaxProfit{{1, 2, 1000, 2, 1}, 999, ""}};
  for (auto test : tests) {
    int actual = SlidingWindow::max_profit(test.prices);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct LongestSubstring {
  std::string input{};
  int expected{};
  std::string message{};
};
TEST(SlidingWindow, it_solves_longest_substring) {
  std::vector<LongestSubstring> tests{
      LongestSubstring{"abcabcbb", 3, ""},
      LongestSubstring{"", 0, ""},
      LongestSubstring{"a", 1, ""},
      LongestSubstring{"bbbb", 1, ""},
  };

  for (const auto& test : tests) {
    int actual = SlidingWindow::length_of_longest_substring(test.input);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct CharacterReplacement {
  std::string s;
  int k;
  int expected;
  std::string message;
};

TEST(SlidingWindow, it_solves_character_replacement) {
  std::vector<CharacterReplacement> tests{
      CharacterReplacement{"ABAB", 2, 4, ""}};
  for (const auto& test : tests) {
    int actual = SlidingWindow::character_replacement(test.s, test.k);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct CheckInclusion {
  std::string s1;
  std::string s2;
  bool expected;
  std::string message;
};
TEST(SlidingWindow, it_solves_check_inclusion) {
  std::vector<CheckInclusion> tests{
      CheckInclusion{"a", "ab", true, "a is included in ab"},
      CheckInclusion{"a", "b", false, "a is not included in b"},
      CheckInclusion{"ab", "aa", false, "ab is not included in aa"},
      CheckInclusion{"aa", "bb", false, "aa is not included in bb"},
      CheckInclusion{"aa", "aa", true, "aa is included in aa"},
      CheckInclusion{"adc", "dcda", true, "abc is included in dcda"},
      CheckInclusion{"ab", "eidbaoooo", true, "ab is included in eidabooo"},
      CheckInclusion{"ab", "eidbooaoo", false,
                     "ab is not included in eidbooaoo"},
      CheckInclusion{"ky", "ainwkckifykxlribaypk", true,
                     "ky is included in ainwkckifykxlribaypk"},
  };

  for (const auto& test : tests) {
    auto actual = SlidingWindow::check_inclusion(test.s1, test.s2);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct MinWindow {
  std::string s;
  std::string t;
  std::string expected;
  std::string message;
};
TEST(SlidingWindow, it_solves_min_window) {
  std::vector<MinWindow> tests{
      MinWindow{"ADOBECODEBANC", "ABC", "BANC", ""},
      MinWindow{"ABCEFS", "ABC", "ABC", ""},
      MinWindow{"SDFDEABC", "ABC", "ABC", ""},
      MinWindow{"XEABCXE", "ABC", "ABC", ""},
      MinWindow{"a", "a", "a", ""},
      MinWindow{"a", "aa", "", ""},
      MinWindow{"a", "", "", ""},
  };
  for (const auto& test : tests) {
    std::string actual = SlidingWindow::min_window(test.s, test.t);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
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
struct MaxSlidingWindow {
  std::vector<int> nums;
  int k;
  std::vector<int> expected;
  std::string message;
};
TEST(SlidingWindow, it_solves_max_sliding_window) {
  std::vector<MaxSlidingWindow> tests{
      //      MaxSlidingWindow{{1, -1}, 1, {1, -1}, ""},
      MaxSlidingWindow{{9, 10, 9, -7, -4, -8, 2, -6}, 5, {10, 10, 9, 2}, ""},
  };
  for (auto test : tests) {
    std::vector<int> actual =
        SlidingWindow::max_sliding_window(test.nums, test.k);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}
