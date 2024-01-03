#include <algorithm>
#include <stack>
#include <string>

namespace l1047 {
class Solution {
public:
  std::string removeDuplicates(std::string s) {
    std::stack<char> stk;
    for (auto c : s) {
      if (!stk.empty() && stk.top() == c) {
        stk.pop();
      } else {
        stk.emplace(c);
      }
    }
    std::string res;
    while (!stk.empty()) {
      res.push_back(stk.top());
      stk.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
}  // namespace l1047