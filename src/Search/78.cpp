#include <vector>

namespace l78 {

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<std::vector<int>> res;
    for (int i = 0; i < 1 << n; ++i) {
      std::vector<int> round;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {
          round.push_back(nums[j]);
        }
      }
      res.push_back(round);
    }
    return res;
  }
};
} // namespace l78