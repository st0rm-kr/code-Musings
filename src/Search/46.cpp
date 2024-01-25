#include <vector>
#include <bitset>

namespace l46 {
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    used.reset();
    dfs(nums);
    return result;
  }

private:
  std::vector<std::vector<int>> result{};
  std::vector<int> path{};
  std::bitset<6> used{};

  void dfs(std::vector<int> &nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i] == 1) {
        continue;
      }
      used[i] = 1;
      path.emplace_back(nums[i]);
      dfs(nums);
      path.pop_back();
      used[i] = 0;
    }
  }
};
}