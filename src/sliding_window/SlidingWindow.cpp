#include "SlidingWindow.h"

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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

int SlidingWindow::length_of_longest_substring(std::string s) {
  if (s.length() < 2) {
    return static_cast<int>(s.length());
  }
  std::size_t left = 0;
  std::size_t right = 1;

  int longest = 0;
  std::unordered_set<char> char_set{s[0]};
  while (right < s.size()) {
    if (char_set.count(s[right]) > 0) {
      longest = std::max(longest, static_cast<int>(char_set.size()));
      left++;
    } else {
      char_set.emplace(s[right]);
    };
    right++;
  }
  return longest;
}

int SlidingWindow::characterReplacement(std::string s, int k) {
  int freq[26]{};
  int mostFreqLetter = 0;
  std::size_t left = 0;
  size_t max = 0;

  for (std::size_t right = 0; right < s.length(); right++) {
    freq[s[right] - 'A']++;
    mostFreqLetter = std::max(mostFreqLetter, freq[s[right] - 'A']);

    int lettersToChange = static_cast<int>(right - left + 1) - mostFreqLetter;
    if (lettersToChange > k) {
      freq[s[left] - 'A']--;
      left++;
    }

    max = std::max(max, right - left + 1);
  }

  return max;
}

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
