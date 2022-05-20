#include "SlidingWindow.h"

#include <algorithm>

int SlidingWindow::max_profit(std::vector<int>& prices) {
  if (prices.size() < 2) {
    return 0;
  }
  std::size_t left = 0;
  std::size_t right = 1;
  int result = 0;
  while (right < prices.size()) {
    int price_left = prices[left];
    int price_right = prices[right];
    int current_profit = price_right - price_left;
    if (current_profit > 0) {
      result = std::max(current_profit, result);
    } else {
      left = right;
    }
    right += 1;
  }
  return result;
}

int SlidingWindow::length_of_longest_substring(std::string s) { return 0; }

int SlidingWindow::characterReplacement(std::string s, int k) { return 0; }

bool SlidingWindow::check_inclusion(std::string s1, std::string s2) {
  return false;
}

std::string SlidingWindow::min_window(std::string s, std::string t) {
  return std::string();
}
std::vector<int> SlidingWindow::max_sliding_window(std::vector<int>& nums,
                                                   int k) {
  return std::vector<int>();
}
