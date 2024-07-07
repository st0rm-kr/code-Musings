#include <vector>

namespace l376 {
class Solution {
public:
  int wiggleMaxLength(std::vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1])
        up = down + 1;
      else if (nums[i] < nums[i - 1])
        down = up + 1;
    }
    return std::max(up, down);
  }
};
} // namespace l376