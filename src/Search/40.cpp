#include <algorithm>
#include <vector>

namespace l40 {
class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> path{};
    std::vector<std::vector<int>> res{};
    auto dfs = [&](auto &&dfs, int u, int sum) {
      if (sum > target) {
        return;
      }
      if (sum == target) {
        res.push_back(path);
        return;
      }
      if (u >= candidates.size()) {
        return;
      }
      for (int i = u; i < candidates.size(); ++i) {
        if (i > u && candidates[i] == candidates[i - 1]) {
          continue;
        }
        path.push_back(candidates[i]);
        dfs(dfs, i + 1, sum + candidates[i]);
        path.pop_back();
      }
    };
    dfs(dfs, 0, 0);
    return res;
  }
};
};