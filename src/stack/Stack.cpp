#include "Stack.h"

#include <stack>
#include <unordered_map>

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
