#include <algorithm>
#include <vector>

namespace l90 {
class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result{};
    for (int i = 0; i < 1 << n; ++i) {
      bool flag = true;
      std::vector<int> path{};
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {
          if (j > 0 && !(i >> (j - 1) & 1) && nums[j] == nums[j - 1]) {
            flag = false;
            break;
          }
          path.push_back(nums[j]);
        }
      }
      if (flag) {
        result.push_back(path);
      }
    }
    return result;
  }
};
} // namespace l90