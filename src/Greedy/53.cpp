#include <algorithm>
#include <vector>

namespace l53 {
class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      nums[i] = std::max(nums[i], nums[i - 1] + nums[i]);
    }
    return *std::max_element(nums.begin(), nums.end());
  }
};
} // namespace l53