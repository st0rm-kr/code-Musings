#include <vector>
#include <algorithm>

using namespace std;

namespace l977 {
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int divide = 0;
    while (divide < nums.size() && nums[divide] < 0) ++divide;
    for_each(nums.begin(), nums.end(), [](auto&& x) { x = x * x; });
    vector<int> res;
    for (int i = divide - 1, j = divide; i >= 0 || j < nums.size();) {
      if (i >= 0 && j < nums.size()) {
        if (nums[i] < nums[j])
          res.emplace_back(nums[i--]);
        else
          res.emplace_back(nums[j++]);
      } else {
        if (i >= 0)
          res.emplace_back(nums[i--]);
        else
          res.emplace_back(nums[j++]);
      }
    }
    return res;
  }
};
}  // namespace l977