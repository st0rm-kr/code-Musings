#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>

namespace l1005 {
class Solution {
public:
  int largestSumAfterKNegations(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }

    int res = std::accumulate(nums.begin(), nums.end(), 0);
    for (int i = -100; i < 0; ++i) {
      if (freq[i]) {
        int ops = std::min(k, freq[i]);
        res += (-i) * ops * 2;
        freq[i] -= ops;
        freq[-i] += ops;
        if (k == 0) {
          break;
        }
      }
    }
    if (k > 0 && k % 2 == 1 && !freq[0]) {
      for (int i = 1; i <= 100; ++i) {
        if (freq[i]) {
          res -= i * 2;
          break;
        }
      }
    }
    return res;
  }
};
} // namespace l1005