#include <vector>

using namespace std;

namespace L34 {

class Solution {
 public:
  template <typename T>
  int BinarySearchLeft(const vector<int> &nums, int begin, int end, int target, T &&cmp) {
    int l = begin, r = end;
    while (l < r) {
      int mid = l + r >> 1;
      if (cmp(target, nums[mid])) l = mid + 1;
      else r = mid;
    }
    return r;
  }
  template <typename T>
  int BinarySearchRight(const vector<int> &nums, int begin, int end, int target,
                       T &&cmp) {
    int l = begin, r = end;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (cmp(target, nums[mid]))
        l = mid;
      else
        r = mid - 1;
    }
    return r;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int res1 = BinarySearchLeft(nums, 0, nums.size() - 1, target,
                            [](int x, int y) { return x > y; });
    if (nums[res1] != target) return {-1, -1};
    int res2 = BinarySearchRight(nums, 0, nums.size() - 1, target,
                                 [](int x, int y) { return x >= y; });
    return {res1, res2};
  }
};

}  // namespace L34