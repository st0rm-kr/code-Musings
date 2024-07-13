#include <vector>

namespace l55 {
class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int distance = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i <= distance) {
        distance = std::max(distance, i + nums[i]);
        if (distance >= nums.size() - 1) {
          return true;
        }
      }
    }
    return false;
  }
};
} // namespace l55