#include <unordered_set>

namespace l202 {
class Solution {
public:
  bool isHappy(int n) {
    std::unordered_set<int> map;
    while (n != 1) {
      int x = n;
      n = 0;
      while (x) {
        int t = x % 10;
        x /= 10;
        n += t * t;
      }
      if (map.count(n))
        return false;
      map.insert(n);
    }
    return true;
  }
};
}  // namespace l202