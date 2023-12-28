#include <unordered_map>
#include <vector>

namespace l454 {
class Solution {
public:
  int fourSumCount(std::vector<int> &nums1, std::vector<int> &nums2,
                   std::vector<int> &nums3, std::vector<int> &nums4) {
    std::unordered_map<int, int> hashMap;
    for (int x : nums1) {
      for (int y : nums2) {
        ++hashMap[x + y];
      }
    }

    auto res = 0;
    for (int x : nums3) {
      for (int y : nums4) {
        if (hashMap.count(-(x + y))) {
          res += hashMap[-(x + y)];
        }
      }
    }
    return res;
  }
};
} // namespace l454