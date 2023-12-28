#include <vector>

using namespace std;

namespace l283 {
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0, n = nums.size();
    while (i < n && j < n) {
      while (j < n && nums[j] != 0) ++j;
      while (i < n && nums[i] == 0) ++i;
      if (i < n && j < n && i > j) swap(nums[i], nums[j]);
      if (i <= j) ++i;
    }
  }
};
}  // namespace l283