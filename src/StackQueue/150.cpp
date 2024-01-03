#include <stack>
#include <string>
#include <vector>

namespace l150 {
class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> nums;

    for (auto &&token : tokens) {
      if (token != "+" && token != "-" && token != "*" && token != "/") {
        nums.push(std::stoi(token));
      } else {
        auto x = nums.top();
        nums.pop();
        auto y = nums.top();
        nums.pop();
        if (token == "+") {
          nums.push(x + y);
        } else if (token == "-") {
          nums.push(y - x);
        } else if (token == "*") {
          nums.push(x * y);
        } else {
          nums.push(y / x);
        }
      }
    }
    return nums.top();
  }
};
}  // namespace l150