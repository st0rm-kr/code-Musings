#include <string>
#include <vector>

namespace l459 {
class Solution {
 public:
  bool repeatedSubstringPattern(std::string s) {
    auto n = s.size();
    std::vector<int> next(n, 0);

    next[0] = -1;
    for (int i = 1, j = -1; i < n; ++i) {
      while (j > -1 && s[i] != s[j + 1]) {
        j = next[j];
      }
      if (s[i] == s[j + 1]) {
        ++j;
      }
      next[i] = j;
    }
    int t = n - next[n - 1] - 1;
    return n > t && n % t == 0;
  }
};
}  // namespace l459