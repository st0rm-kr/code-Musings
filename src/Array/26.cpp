#include <vector>

using namespace std;

// [1,1,2]
// [0,0,1,1,1,2,2,3,3,4]

namespace l26 {
class Solution {
 public:
  template <typename T>
  int unique(vector<T> &nums) {
    auto n = nums.size();
    int i = 0, j = 0;
    while (++i != n) {  
      if (nums[j] != nums[i]) nums[++j] = nums[i];
    }
    return ++j;
  }
  int removeDuplicates(vector<int>& nums) {
    return unique(nums);
  }
};
}  // namespace l26