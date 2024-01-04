#include <queue>
#include <unordered_map>

namespace l347 {
class Solution {
public:
  struct cmp {
    bool operator()(const std::pair<int, int> &lhs,
                    const std::pair<int, int> &rhs) {
      return lhs.second > rhs.second;
    }
  };
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    for (auto x : nums) {
      ++map[x];
    }

    // 取决于cmp，这是一个小根堆
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        cmp>
        heap;
    for (auto x : map) {
      heap.emplace(x);
      if (heap.size() > k) {
        heap.pop();
      }
    }

    std::vector<int> res(k);
    for (auto itr = res.rbegin(); itr != res.rend(); ++itr) {
      *itr = heap.top().first;
      heap.pop();
    }
    return res;
  }
};
} // namespace l347