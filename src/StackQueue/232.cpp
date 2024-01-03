#include <stack>

namespace l232 {
class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    s1.push(x);
  }

  int pop() {
    if (!s2.empty()) {
      auto res = s2.top();
      s2.pop();
      return res;
    }
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    if (!s2.empty()) {
      auto res = s2.top();
      s2.pop();
      return res;
    }
    return -1;
  }

  int peek() {
    if (!s2.empty()) {
      return s2.top();
    }
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    if (!s2.empty()) {
      return s2.top();
    }
    return -1;
  }

  bool empty() {
    return s1.empty() && s2.empty();
  }

private:
  std::stack<int> s1;
  std::stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
} // namespace l232