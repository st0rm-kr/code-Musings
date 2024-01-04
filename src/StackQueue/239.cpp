#include <queue>
#include <vector>

namespace l239 {
class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    auto n = nums.size();
    using size_type = decltype(n);

    std::deque<size_type> q;
    std::vector<int> res;
    for (size_type i = 0; i < n; ++i) {
      if (!q.empty() && q.back() - q.front() + 1 >= k) {
        q.pop_front();
      }
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }
      q.emplace_back(i);
      if (i >= k - 1) {
        res.emplace_back(nums[q.front()]);
      }
    }
    return res;
  }
};
}  // namespace l239