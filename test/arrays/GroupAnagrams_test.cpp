#include "arrays/GroupAnagrams.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_map>

TEST(GroupAnagrams, exmaple) {
  std::vector<std::vector<std::string>> expected = {
      {"bat"}, {"tan", "nat"}, {"ate", "eat", "tea"}};
  for (std::vector<std::string> &group : expected) {
    std::sort(group.begin(), group.end());
  }
  std::sort(
      expected.begin(), expected.end(),
      [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
        return (a.size() < b.size()) ||
               (!(a.size() > b.size()) && (a.size() < b.size()));
      });

  std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> actual = GroupAnagrams::solve(input);
  for (std::vector<std::string> &group : actual) {
    std::sort(group.begin(), group.end());
  }
  std::sort(
      actual.begin(), actual.end(),
      [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
        return (a.size() < b.size()) ||
               (!(a.size() > b.size()) && (a.size() < b.size()));
      });

  EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";
}
