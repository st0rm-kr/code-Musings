#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace l51 {
class Solution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::function<void(int)> dfs = [&](int r) {
      if (r == n) {
        std::vector<std::string> board(n);
        for (int i = 0; i < n; ++i) {
          board[i] =
              std::string(row[i], '.') + 'Q' + std::string(n - 1 - row[i], '.');
        }
        res.push_back(board);
        return;
      }
      for (int c = 0; c < n; ++c) {
        int t1 = r - c, t2 = r + c;
        if (!col[c] && !diag1[t1] && !diag2[t2]) {
          row[r] = c;
          col[c] = diag1[t1] = diag2[t2] = true;
          dfs(r + 1);
          col[c] = diag1[t1] = diag2[t2] = false;
        }
      }
    };
    dfs(0);
    return res;
  }

private:
  std::unordered_map<int, int> row, col, diag1, diag2;
};
} // namespace l51