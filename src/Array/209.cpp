#include <numeric>
#include <vector>

using namespace std;

namespace l209 {
class Solution {
public:
  // 前缀和解法
  int minSubArrayLen(int target, vector<int> &nums) {
    auto n = nums.size();
    vector<int> prefix(n + 1, 0);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
      int l = i, r = n;
      while (l < r) {
        int mid = l + r >> 1;
        if (prefix[mid] - prefix[i - 1] >= target)
          r = mid;
        else
          l = mid + 1;
      }
      if (prefix[r] - prefix[i - 1] >= target) res = min(res, r - i + 1);
    }
    return res == 0x3f3f3f3f ? 0 : res;
  }

  // 双指针解法
  int minSubArrayLen2(int target, vector<int> &nums) {
    auto n = nums.size();
    int res = 0x3f3f3f3f;
    int sum = nums[0];
    for (int i = 0, j = 0; i < n; ++i) {
      while (j + 1 < n && sum < target)
        sum += nums[++j];
      if (sum >= target)
        res = min(res, j - i + 1);
      sum -= nums[i];
    }
    return res == 0x3f3f3f3f ? 0 : res;
  }
};
} // namespace l209