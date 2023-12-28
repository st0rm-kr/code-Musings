#include <string>

namespace l242 {
class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    int map[26] = {0};

    for (auto c : s) --map[c - 'a'];
    for (auto c : t) ++map[c - 'a'];
    for (auto x : map) {
      if (x != 0) return false;
    }
    return true;
  }
};
}  // namespace l242