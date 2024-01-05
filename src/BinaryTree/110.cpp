#include "treeNode.h"
#include <algorithm>

namespace l110 {
class Solution {
public:
  auto height(TreeNode *root) -> int {
    if (root == nullptr) {
      return 0;
    }
    return std::max(height(root->left), height(root->right)) + 1;
  }
  bool isBalanced(TreeNode *root) {
    if (root) {
      return isBalanced(root->left) && isBalanced(root->right) &&
             std::abs(height(root->left) - height(root->right)) <= 1;
    }
    return true;
  }
};
}  // namespace l110