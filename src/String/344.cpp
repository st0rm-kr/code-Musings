#include <vector>

namespace l344 {
class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    auto n = s.size();
    for (decltype(n) i = 0, j = n - 1; i < n / 2; ++i, --j) {
      std::swap(s[i], s[j]);
    }
  }
};
}