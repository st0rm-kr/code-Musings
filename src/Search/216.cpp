#include <vector>
#include <algorithm>

namespace l216 {
class Solution {
public:
  std::vector<std::vector<int>> res{};
  void dfs(int u, int sum, std::vector<int> &path) {
    if (path.size() == k_) {
      if (sum == n_) {
        res.push_back(path);
      }
      return;
    }
    if (path.size() + (9 - u + 1) < k_) {
      return;
    }
    if (sum >= n_) {
      return;
    }
    for (int i = u; i <= 9; ++i) {
      path.emplace_back(i);
      dfs(i + 1, sum + i, path);
      path.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    k_ = k;
    n_ = n;
    std::vector<int> path{};
    dfs(1, 0, path);
    return res;
  }

private:
  int n_;
  int k_;
};
}  // namespace l216