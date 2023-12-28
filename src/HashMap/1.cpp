#include <vector>
#include <unordered_map>

namespace l1 {
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      int x = target - nums[i];
      if (map.count(x)) {
        return {map[x], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};
}  // namespace l1