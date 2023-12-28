#include <vector>
#include <unordered_set>

namespace l349 {
class Solution {
 public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::unordered_set<int> res;
    std::unordered_set<int> s;
    for (int x : nums1) s.insert(x);
    for (int x : nums2) {
      if (s.count(x)) {
        res.insert(x);
      }
    }
    return {res.begin(), res.end()};
  }
};
}  // namespace l349