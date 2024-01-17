#include <vector>

namespace l77 {
class Solution {
public:
  int k_{};;
  int n_{};
  std::vector<std::vector<int>> res{};
  void dfs(int u, std::vector<int> &path) {
    if (path.size() == k_) {
      res.push_back(path);
      return;
    }

    for (int i = u; i <= n_; ++i) {
      path.emplace_back(i);
      dfs(i + 1, path);
      path.pop_back();
    }
  }
  std::vector<std::vector<int>> combine(int n, int k) {
    n_ = n;
    k_ = k;
    std::vector<int> path;
    dfs(1, path);
    return res;
  }
};
}  // namespace l77