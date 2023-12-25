#include <vector>

using namespace std;

namespace l59 {
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    int x = 0, y = 0, d = 0;
    for (int i = 1; i <= n * n; ++i) {
      res[x][y] = i;

      int nx = x + dx[d], ny = y + dy[d];
      if ((nx < 0 || nx >= n || ny < 0 || ny >= n) || res[nx][ny] != 0) {
        d = (d + 1) % 4;
        nx = x + dx[d], ny = y + dy[d];
      }
      x = nx, y = ny;
    }
    return res;
  }

private:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
};
}