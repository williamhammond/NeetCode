#include <gtest/gtest.h>
#include <stack/MinStack.h>

#include <string>
#include <vector>

struct MinStackTest {
  std::vector<int> input;
  std::vector<int> output;
  std::vector<int> minimum;
  std::string message;
};

TEST(MinStack, it_pushs_and_pops) {
  std::vector<MinStackTest> tests = {
      MinStackTest{{1}, {1}, {1}, ""},
      MinStackTest{{1, 2, 3}, {3, 2, 1}, {1, 1, 1}, ""},
      MinStackTest{{3, 2, 1},
                   {1, 2, 3},
                   {
                       1,
                       2,
                       3,
                   },
                   ""},
  };
  auto *stack = new MinStack();
  for (auto test : tests) {
    for (auto input : test.input) {
      stack->push(input);
    }
    for (std::size_t i = 0; i < test.output.size(); i++) {
      auto expected_value = test.output[i];
      EXPECT_EQ(expected_value, stack->top());
      auto expected_minimum = test.minimum[i];
      EXPECT_EQ(expected_minimum, stack->getMin());
      stack->pop();
    };
  }
  EXPECT_EQ(true, stack->isEmpty());
}
