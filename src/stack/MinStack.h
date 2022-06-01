#ifndef NEETCODE_SRC_STACK_MINSTACK_H_
#define NEETCODE_SRC_STACK_MINSTACK_H_

#include <vector>

class MinStack {
 public:
  MinStack();
  void push(int val);
  void pop();
  int top();
  int getMin();
  bool isEmpty();

 private:
  struct Node {
    int value;
    int min;
  };
  std::vector<Node> data;
};

#endif  // NEETCODE_SRC_STACK_MINSTACK_H_
