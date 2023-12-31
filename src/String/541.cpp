#include <string>
#include <algorithm>

namespace l541 {
class Solution {
 public:
  std::string reverseStr(std::string s, int k) {
    auto n = s.size();
    for (decltype(n) i = 0; i < n; i += (k + k)) {
      if (i + k <= n) {
        std::reverse(s.begin() + i, s.begin() + i + k);
      } else {
        std::reverse(s.begin() + i, s.end());
      }
    }
    return s;
  }
};
}  // namespace l541