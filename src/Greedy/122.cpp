#include <algorithm>
#include <vector>

namespace l122 {
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = prices.size();

    std::vector<std::vector<int>> f(n, std::vector<int>(2, 0));
    // f[i][0]代表第i天不持有股票的最大利润
    // f[i][1]代表第i天持有股票的最大利润
    f[0][0] = 0;
    f[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      f[i][0] = std::max(f[i - 1][0], f[i - 1][1] + prices[i]);
      f[i][1] = std::max(f[i - 1][1], f[i - 1][0] - prices[i]);
    }
    return f[n - 1][0];
  }
};
} // namespace l122