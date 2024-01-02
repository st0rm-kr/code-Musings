#include <vector>

namespace l27 {
class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    auto n = nums.size();

    using size_type = decltype(n);
    size_type i = 0, j = 0;
    while (i < n) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
      ++i;
    }
    nums.resize(j);
    return j;
  }
};
}  // namespace l27