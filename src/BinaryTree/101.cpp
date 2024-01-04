#include "treeNode.h"

namespace l101 {
class Solution {
public:
  auto dfs(TreeNode *left, TreeNode *right) -> bool {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;
    if (left->val != right->val)
      return false;
    return dfs(left->left, right->right) && dfs(left->right, right->left);
  }
  bool isSymmetric(TreeNode *root) {
    return !root || dfs(root->left, root->right);
  }
};
}  // namespace l101