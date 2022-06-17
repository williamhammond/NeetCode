#ifndef NEETCODE_SRC_STACK_STACK_H_
#define NEETCODE_SRC_STACK_STACK_H_

#include <string>
#include <vector>

class Stack {
 public:
  static bool isValidParens(std::string s);
  static int evalRPN(std::vector<std::string>& tokens);
  static std::vector<std::string> generateParenthesis(int n);
  static std::vector<int> dailyTemperatures(
      const std::vector<int>& temperatures);
  static int carFleet(int target, const std::vector<int>& position,
                      const std::vector<int>& speed);
};

#endif  // NEETCODE_SRC_STACK_STACK_H_
