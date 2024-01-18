#include <vector>

namespace l39 {
class Solution {
 public:
  void dfs(int u, int sum, int target, const std::vector<int> &candidates,
           std::vector<int> &path) {
    if (sum == target) {
      res.push_back(path);
      return;
    }
    if (sum > target) {
      return;
    }

    for (int i = u; i < candidates.size(); ++i) {
      path.emplace_back(candidates[i]);
      dfs(i, sum + candidates[i], target, candidates, path);
      path.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<int> path;
    dfs(0, 0, target, candidates, path);
    return res;
  }

 private:
  std::vector<std::vector<int>> res{};
};
}  // namespace l39