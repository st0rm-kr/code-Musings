#include "treeNode.h"
#include <vector>

namespace l108 {
class Solution {
 public:
  TreeNode* helper(std::vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    size_t mid = (left + right) / 2;
    auto *root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
  }
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};
}  // namespace l108