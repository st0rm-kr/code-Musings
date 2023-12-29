#include <string>
#include <array>

namespace l383 {
class Solution {
 public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    constexpr int types = 26; // 字符的种类个数
    std::array<int, types> map = {0};

    for (auto c : magazine) {
      ++map.at(c - 'a');
    }
    for (auto c : ransomNote) {
      --map.at(c - 'a');
      if (map.at(c - 'a') < 0) {
        return false;
      }
    }
    return true;
  }
};
}  // namespace l383