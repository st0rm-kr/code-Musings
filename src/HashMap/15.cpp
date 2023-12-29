#include <vector>
#include <algorithm>

namespace l15 {
class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;

    auto n = nums.size();
    for (decltype(n) i = 0; i < n; ++i) {
      while (i && i < n && nums[i] == nums[i - 1]) {
        ++i;
      }
      if (i >= n - 1) {
        break;
      }
      int target = -nums[i];
      for (decltype(n) j = i + 1, k = n - 1; j < n; ++j) {
        while (j < n && j > i + 1 && nums[j] == nums[j - 1]) {
          ++j;
        }
        while (k > j && nums[j] + nums[k] > target) {
          --k;
        }
        if (j >= k) {
          break;
        }
        if (nums[j] + nums[k] == target) {
          res.emplace_back();
          res.back().emplace_back(nums[i]);
          res.back().emplace_back(nums[j]);
          res.back().emplace_back(nums[k]);
        }
      }
    }
    return res;
  }
};
}  // namespace l15