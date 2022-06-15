#ifndef NEETCODE_SRC_STACK_STACK_H_
#define NEETCODE_SRC_STACK_STACK_H_

#include <string>
#include <vector>

class Stack {
 public:
  static bool isValidParens(std::string s);
  static int evalRPN(std::vector<std::string>& tokens);
  static std::vector<std::string> generateParenthesis(int n);
};

#endif  // NEETCODE_SRC_STACK_STACK_H_
