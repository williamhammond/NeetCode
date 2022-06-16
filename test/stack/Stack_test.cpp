#include <gtest/gtest.h>
#include <stack/Stack.h>

#include <string>
#include <vector>

struct ValidParens {
  std::string s{};
  bool expected{};
  std::string message{};
};
TEST(Stack, it_solves_max_profit) {
  std::vector<ValidParens> tests{
      ValidParens{"()", true, "() is valid"},
      ValidParens{"[]", true, "[] is valid"},
      ValidParens{"{}", true, "{} is valid"},
      ValidParens{"()[]{}", true, "()[]{} is valid"},
      ValidParens{"(]", false, "(] is valid"},
      ValidParens{"(", false, "( is not valid"},
      ValidParens{")", false, ") is not valid"},
      ValidParens{"[", false, "[ is not valid"},
      ValidParens{"]", false, "] is not valid"},
      ValidParens{"{", false, "{ is not valid"},
      ValidParens{"}", false, "} is not valid"},
  };
  for (auto test : tests) {
    auto actual = Stack::isValidParens(test.s);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct RPN {
  std::vector<std::string> tokens;
  int expected;
  std::string message;
};

TEST(Stack, it_solves_rpn) {
  std::vector<RPN> tests{
      RPN{{"2", "1", "+", "3", "*"}, 9, "((2 + 1) * 3) != "},
      RPN{{"2", "1", "+"}, 3, "(2 + 1) != "},
      RPN{{"2", "1", "-"}, 1, "(2 - 1) != "},
      RPN{{"20", "1", "*"}, 20, "(20 * 1) != "},
      RPN{{"4", "2", "/"}, 2, "(4 * 2) != "},
      RPN{{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"},
          22,
          "((10 * (6 / ((9 + 3) * -11))) + 17) + 5 != "},
  };
  for (auto test : tests) {
    auto actual = Stack::evalRPN(test.tokens);
    EXPECT_EQ(test.expected, actual) << test.message << actual;
  }
}

struct GenerateParenthesis {
  int n;
  std::vector<std::string> expected;
  std::string message;
};

TEST(Stack, it_solves_generate_parenthesis) {
  std::vector<GenerateParenthesis> tests{
      GenerateParenthesis{0, {""}, ""},
      GenerateParenthesis{1, {"()"}, ""},
      GenerateParenthesis{2, {"()()", "(())"}, ""},
      GenerateParenthesis{
          3, {"()()()", "()(())", "(())()", "(()())", "((()))"}, ""},
  };

  for (const auto& test : tests) {
    auto actual = Stack::generateParenthesis(test.n);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}

struct DailyTemperature {
  std::vector<int> temperatures;
  std::vector<int> expected;
  std::string message;
};
TEST(Stack, it_solves_daily_temperatures) {
  std::vector<DailyTemperature> tests{
      DailyTemperature{{1}, {0}, ""},
      DailyTemperature{{30, 60, 90}, {1, 1, 0}, ""},
      DailyTemperature{{30, 40, 50, 60}, {1, 1, 1, 0}, ""},
      DailyTemperature{
          {73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}, ""},
  };

  for (const auto& test : tests) {
    auto actual = Stack::dailyTemperatures(test.temperatures);
    EXPECT_EQ(test.expected, actual) << test.message;
  }
}
