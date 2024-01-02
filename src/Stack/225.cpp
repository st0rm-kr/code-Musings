#include <deque>

namespace l225 {
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    queue.push_back(x);
  }

  int pop() {
    auto res = queue.back();
    queue.pop_back();
    return res;
  }

  int top() {
    return queue.back();
  }

  bool empty() {
    return queue.empty();
  }

private:
  std::deque<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
}