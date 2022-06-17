#include "Stack.h"

#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

static void generateParenthesisHelper(std::vector<std::string>& v,
                                      std::string value, int left, int right) {
  if (left == 0 && right == 0) {
    v.push_back(value);
    return;
  }
  if (right > 0) {
    generateParenthesisHelper(v, value + ")", left, right - 1);
  }
  if (left > 0) {
    generateParenthesisHelper(v, value + "(", left - 1, right + 1);
  }
}

std::vector<std::string> Stack::generateParenthesis(int n) {
  std::vector<std::string> result{};
  generateParenthesisHelper(result, "", n, 0);
  return result;
}

std::vector<int> Stack::dailyTemperatures(
    const std::vector<int>& temperatures) {
  std::vector<int> result(temperatures.size(), 0);

  std::stack<std::pair<int, std::size_t>> temp_stack;
  for (std::size_t i = 0; i < temperatures.size(); i++) {
    auto temperature = temperatures[i];
    while (!temp_stack.empty() && temperature > temp_stack.top().first) {
      std::size_t temp_index = temp_stack.top().second;
      result[temp_index] = i - temp_index;
      temp_stack.pop();
    }
    temp_stack.push({temperature, i});
  }
  return result;
}

struct Car {
  int position;
  int speed;
};

struct CarComparator {
  bool operator()(const Car& a, const Car& b) const {
    return a.position < b.position;
  }
};

int Stack::carFleet(int target, const std::vector<int>& position,
                    const std::vector<int>& speed) {
  std::size_t n = position.size();
  std::vector<Car> cars{};
  for (std::size_t i = 0; i < n; i++) {
    auto car = Car{position[i], speed[i]};
    cars.push_back(car);
  }
  std::make_heap(cars.begin(), cars.end(), CarComparator());
  std::sort_heap(cars.begin(), cars.end(), CarComparator());

  std::stack<float> time_stack;
  for (std::size_t i = 0; i < n; i++) {
    float time =
        (target - cars.at(i).position) / static_cast<float>(cars.at(i).speed);
    while (!time_stack.empty() && time >= time_stack.top()) {
      time_stack.pop();
    }
    time_stack.push(time);
  }
  return time_stack.size();
}
