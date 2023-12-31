#include <string>
#include <algorithm>

namespace l151 {
class Solution {
 public:
  void deleteRedundantSpaces(std::string &s) {
    auto n = s.size();
    decltype(n) i = 0, j = 0;
    for (; i < n; ++i) {
      if (s[i] != ' ') {
        if (j != 0) {
          s[j++] = ' ';
        }
        while (i < n && s[i] != ' ') {
          s[j++] = s[i++];
        }
      }
    }
    s.resize(j);
  }
  void reverseEachWord(std::string &s) {
    auto n = s.size();
    decltype(n) i = 0, j = 0;
    while (i < n) {
      while (j < n && s[j] != ' ') {
        ++j;
      }
      if (j >= n) {
        break;
      }
      std::reverse(s.begin() + i, s.begin() + j);
      i = ++j;
    }
    if (i < n) {
      std::reverse(s.begin() + i, s.end());
    }
  }
  std::string reverseWords(std::string s) {
    deleteRedundantSpaces(s);
    std::reverse(s.begin(), s.end());
    reverseEachWord(s);
    return s;
  }
};
}