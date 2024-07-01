#include <algorithm>
#include <vector>
#include <bitset>

namespace l47 {
class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    dfs(nums);
    return result;
  }

private:
  std::vector<std::vector<int>> result{};
  std::vector<int> path{};
  std::bitset<8> used{};
  void dfs(std::vector<int> &nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] == nums[i - 1] && used[i - 1] == 0) {
        continue;
      }
      if (used[i] == 0) {
        used[i] = 1;
        path.push_back(nums[i]);
        dfs(nums);
        path.pop_back();
        used[i] = 0;
      }
    }
  }
};
} // namespace l47