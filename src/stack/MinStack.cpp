#include "MinStack.h"

#include <algorithm>

MinStack::MinStack() { data = std::vector<Node>(); }

void MinStack::push(int val) {
  if (isEmpty()) {
    data.insert(data.begin(), Node{val, val});
  } else {
    data.insert(data.begin(), Node{val, std::min(val, getMin())});
  }
}

void MinStack::pop() { data.erase(data.begin()); }

int MinStack::top() { return data[0].value; }

int MinStack::getMin() { return data[0].min; }

bool MinStack::isEmpty() { return data.empty(); }
