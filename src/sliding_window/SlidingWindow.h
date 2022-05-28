
#ifndef NEETCODE_SRC_SLIDING_WINDOW_SLIDINGWINDOW_H_
#define NEETCODE_SRC_SLIDING_WINDOW_SLIDINGWINDOW_H_

#include <string>
#include <vector>

class SlidingWindow {
 public:
  /**
   * You are given an array prices where prices[i] is the price of a given stock
   * on the ith day. You want to maximize your profit by choosing a single day
   * to buy one stock and choosing a different day in the future to sell that
   * stock. Return the maximum profit you can achieve from this transaction. If
   * you cannot achieve any profit, return 0.
   */
  static int max_profit(std::vector<int>& prices);

  /**
   *  Given a string s, find the length of the longest substring without
   * repeating characters.
   */
  static int length_of_longest_substring(std::string s);

  /**
   * You are given a string s and an integer k. You can choose any character of
   * the string and change it to any other uppercase English character. You can
   * perform this operation at most k times. Return the length of the longest
   * substring containing the same letter you can get after performing the above
   * operations.
   */
  static int character_replacement(std::string s, int k);

  /**
   *  Given two strings s1 and s2, return true if s2 contains a permutation of
   * s1, or false otherwise. In other words, return true if one of s1's
   * permutations is the substring of s2.
   */
  static bool check_inclusion(std::string s1, std::string s2);

  /**
   *  Given two strings s and t of lengths m and n respectively,
   *  return the minimum window substring of s such that every character in t
   * (including duplicates) is included in the window. If there is no such
   * substring, return the empty string "". The testcases will be generated such
   * that the answer is unique. A substring is a contiguous sequence of
   * characters within the string.
   */
  static std::string min_window(std::string s, std::string t);

  /**
   * You are given an array of integers nums, there is a sliding window of size
   * k which is moving from the very left of the array to the very right. You
   * can only see the k numbers in the window. Each time the sliding window
   * moves right by one position. Return the max sliding window.
   */
  static std::vector<int> max_sliding_window(std::vector<int>& nums, int k);
};

#endif  // NEETCODE_SRC_SLIDING_WINDOW_SLIDINGWINDOW_H_
