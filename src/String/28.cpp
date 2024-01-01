#include <string>
#include <vector>

namespace l28 {
class Solution {
 public:
  int kmp(const std::string &s, const std::string &t) {
    // 查找字符串s是否在字符串t中出现
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

    auto m = t.size();
    for (int i = 0, j = -1; i < m; ++i) {
      while (j > -1 && t[i] != s[j + 1]) {
        j = next[j];
      }
      if (t[i] == s[j + 1]) {
        ++j;
      }
      if (j == n - 1) {
        return i - n + 1;
      }
    }
    return -1;
  }
  int strStr(std::string haystack, std::string needle) {
    return kmp(needle, haystack);
  }
};
}  // namespace l28