#include "Stack.h"

#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool Stack::isValidParens(std::string s) {
  std::stack<char> closed_stack{};
  for (auto c : s) {
    if (c == '(') {
      closed_stack.push(')');
    } else if (c == '{') {
      closed_stack.push('}');
    } else if (c == '[') {
      closed_stack.push(']');
    } else if (closed_stack.empty()) {
      return false;
    } else {
      char closed = closed_stack.top();
      closed_stack.pop();
      if (closed != c) {
        return false;
      }
    }
  }

  return closed_stack.empty();
}

bool is_integer(std::string s) {
  if (s.empty()) {
    return false;
  }

  std::size_t i = 0;
  if (s[0] == '-') {
    if (s.size() == 1) {
      return false;
    }
    i++;
  }
  while (i < s.size()) {
    auto c = s[i];
    if (!std::isdigit(c)) {
      return false;
    }
    i++;
  }

  return true;
}

int Stack::evalRPN(std::vector<std::string>& tokens) {
  std::stack<int> stack{};
  std::unordered_set<char> operators = {'+', '-', '*', '/'};
  for (auto token : tokens) {
    bool isOperator = !is_integer(token);
    if (isOperator) {
      auto y = stack.top();
      stack.pop();
      auto x = stack.top();
      stack.pop();

      switch (token[0]) {
        case '+':
          x += y;
          break;
        case '/':
          x /= y;
          break;
        case '*':
          x *= y;
          break;
        case '-':
          x -= y;
          break;
      }
      stack.push(x);
    } else {
      stack.push(std::stoi(token));
    }
  }
  return stack.top();
}
