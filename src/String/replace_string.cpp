#include <string>

namespace replace_string {
class Solution {
 public:
  void replaceString(std::string &str) {
    auto n = str.size();
    auto cnt = 0;
    for (auto c : str) {
      if (c >= '0' && c <= '9') {
        ++cnt;
      }
    }

    decltype(n) m = n + 5 * cnt;
    str.resize(m);

    for (decltype(n) i = n - 1, j = m - 1; i < j; --i, --j) {
      if (str[i] > '9' || str[i] < '0') {
        str[j] = str[i];
      } else {
        str[j] = 'r', str[j - 1] = 'e', str[j - 2] = 'b', str[j - 3] = 'm',
        str[j - 4] = 'u', str[j - 5] = 'n';
        j -= 5;
      }
    }
  }
};
}