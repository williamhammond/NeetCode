#include "SlidingWindow.h"

#include <algorithm>
#include <limits>
#include <map>
#include <queue>
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

int SlidingWindow::character_replacement(std::string s, int k) {
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
  int s1_freq[26]{};
  for (auto c : s1) {
    s1_freq[c - 'a']++;
  }

  int window_freq[26]{};
  std::size_t left{};
  std::copy(std::begin(s1_freq), std::end(s1_freq), std::begin(window_freq));
  for (std::size_t right = 0; right < s2.size(); right++) {
    auto c = s2[right];
    window_freq[c - 'a']--;
    if (window_freq[c - 'a'] < 0) {
      while (left <= right && window_freq[s2[left] - 'a'] < 0) {
        window_freq[s2[left] - 'a']++;
        left++;
      }
    }

    bool all_0 = true;
    for (auto count : window_freq) {
      if (count != 0) {
        all_0 = false;
        break;
      }
    }
    if (all_0) {
      return true;
    }
  }
  return false;
}

std::string SlidingWindow::min_window(std::string s, std::string t) {
  std::vector<int> t_freq(128, 0);
  for (auto c : t) {
    t_freq[c]++;
  }

  std::size_t counter = t.size();
  std::size_t left = 0;
  std::size_t right = 0;

  std::size_t best_start = 0;
  std::size_t best_length = INT64_MAX;
  while (right < s.size()) {
    if (t_freq[s[right]] > 0) {
      counter--;
    }
    t_freq[s[right]]--;
    right++;

    while (counter == 0) {
      if (right - left < best_length) {
        best_start = left;
        best_length = right - best_start;
      }
      if (t_freq[s[left]] == 0) {
        counter++;
      }
      t_freq[s[left]]++;
      left++;
    }
  }

  return best_length == INT64_MAX ? "" : s.substr(best_start, best_length);
}

std::vector<int> SlidingWindow::max_sliding_window(std::vector<int>& nums,
                                                   int k) {
  std::vector<int> result;
  std::deque<int> dq;
  for (std::size_t i = 0; i < nums.size(); i++) {
    while (!dq.empty() && dq.back() < nums[i]) {
      dq.pop_back();
    }
    dq.push_back(nums[i]);
    if (i >= k - 1) {
      result.push_back(dq.front());
      if (nums[i - k + 1] == dq.front()) {
        dq.pop_front();
      }
    }
  }
  return result;
}
