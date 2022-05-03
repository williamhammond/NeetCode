#include <gtest/gtest.h>
#include "../../src/arrays/public/GroupAnagrams.h"

#include<algorithm>

TEST(GroupAnagrams, exmaple) {
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> actual = GroupAnagrams::solve(input);
    std::vector<std::vector<std::string>> expected = {{"bat"},
                                                      {"nat", "tan"},
                                                      {"ate", "eat", "tea"}};
    std::vector<std::string> test = {"tan", "nat"};
    std::sort(test.begin(), test.end());
    for (auto group: actual) {
        std::sort(group.begin(), group.end());
    }
    std::sort(actual.begin(), actual.end(),
              [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
                  return a.size() - b.size();
              });

    for (auto group: expected) {
        std::sort(group.begin(), group.end());
    }
    std::sort(expected.begin(), expected.end(),
              [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
                  return a.size() - b.size();
              });

    EXPECT_EQ(expected, actual) << "Anagrams grouped incorrectly";
}
