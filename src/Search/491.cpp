#include <unordered_set>
#include <vector>

namespace l491 {
class Solution {
public:
  std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
    dfs(0, nums);
    return result;
  }

private:
  std::vector<std::vector<int>> result{};
  std::vector<int> path{};
  void dfs(int u, const std::vector<int> &nums) {
    if (path.size() > 1) {
      result.push_back(path);
    }
    std::unordered_set<int> set;
    for (int i = u; i < nums.size(); ++i) {
      if ((!path.empty() && nums[i] < path.back()) || set.count(nums[i]) != 0) {
        continue;
      }
      set.insert(nums[i]);
      path.emplace_back(nums[i]);
      dfs(i + 1, nums);
      path.pop_back();
    }
  }
};
} // namespace l419