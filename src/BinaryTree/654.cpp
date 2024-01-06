#include "treeNode.h"
#include <algorithm>
#include <vector>

namespace l654 {
class Solution {
 public:
  TreeNode *build(std::vector<int> &nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    auto pos = std::max_element(nums.begin() + l, nums.begin() + r + 1);
    auto index = pos - nums.begin();
    auto *root = new TreeNode(*pos);
    root->left = build(nums, l, index - 1);
    root->right = build(nums, index + 1, r);
    return root;
  }
  TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    auto res = build(nums, 0, nums.size() - 1);
    return res;
  }
};
}  // namespace l654