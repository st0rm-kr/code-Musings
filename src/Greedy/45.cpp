#include <vector>

namespace l45 {
class Solution {
public:
  int jump(std::vector<int> &nums) {
    int n = nums.size();

    // 一轮跳跃的左右区间[rl, rr]
    int rl = 0, rr = 0;
    int dist = 0, step = 0;
    while (rr < n - 1) {
      for (int i = rl; i <= rr; ++i) {
        dist = std::max(dist, i + nums[i]);
      }
      rl = rr + 1;
      rr = dist;
      ++step;
    }
    return step;
  }
};
} // namespace l45