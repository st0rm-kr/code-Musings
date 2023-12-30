#include <vector>
#include <algorithm>

namespace l18 {
class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    auto n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;

    for (decltype(n) i = 0; i < n; ++i) {
      while (i < n && i > 0 && nums[i] == nums[i - 1]) {
        ++i;
      }
      if (i >= n - 1) {
        break;
      }
      for (auto j = i + 1; j < n; ++j) {
        while (j > i + 1 && j < n && nums[j] == nums[j - 1]) {
          ++j;
        }
        if (j >= n - 1) {
          break;
        }
        long long s = (long long)target - nums[i] - nums[j];
        for (auto k = j + 1, l = n - 1; k < n; ++k) {
          while (k < n && k > j + 1 && nums[k] == nums[k - 1]) {
            ++k;
          }
          while (l > k && nums[k] + nums[l] > s) {
            --l;
          }
          if (k >= l) {
            break;
          }
          if (nums[l] + nums[k] == s) {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
          }
        }
      }
    }
    return res;
  }
};
}