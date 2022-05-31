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
