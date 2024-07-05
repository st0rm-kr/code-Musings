#include <string>
#include <unordered_map>
#include <vector>

namespace l37 {
class Solution {
public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    // 初始化哈希表
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0';
          row[i][num - 1] = true;
          col[j][num - 1] = true;
          cell[i / 3][j / 3][num - 1] = true;
        } else {
          spaces.push_back({i, j});
        }
      }

    dfs(board, 0);
  }

private:
  bool row[9][9];
  bool col[9][9];
  bool cell[3][3][9];
  bool done{false};
  std::vector<std::pair<int, int>> spaces;

  void dfs(std::vector<std::vector<char>> &board, int pos) {
    if (pos == spaces.size()) {
      done = true;
      return;
    }
    auto [r, c] = spaces[pos];
    for (int k = 0; k < 9 && !done; ++k) {
      if (isValid(r, c, k)) {
        row[r][k] = col[c][k] = cell[r / 3][c / 3][k] = true;
        board[r][c] = '0' + k + 1;
        dfs(board, pos + 1);
        row[r][k] = col[c][k] = cell[r / 3][c / 3][k] = false;
      }
    }
  }

  bool isValid(int r, int c, int num) {
    return !row[r][num] && !col[c][num] && !cell[r / 3][c / 3][num];
  }
};
} // namespace l37