#include <string>
#include <stack>

namespace l20 {
class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stk;
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        stk.emplace(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        auto t = stk.top();
        stk.pop();
        if (c == '}' && t != '{') {
          return false;
        }
        if (c == ']' && t != '[') {
          return false;
        }
        if (c == ')' && t != '(') {
          return false;
        }
      }
    }
    return stk.empty();
  }
};
}  // namespace l20