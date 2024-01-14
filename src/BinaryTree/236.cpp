#include "treeNode.h"

namespace l236 {
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == p || root == q || !root) {
      return root;
    }
    auto *left = lowestCommonAncestor(root->left, p, q);
    auto *right = lowestCommonAncestor(root->right, p, q);
    if (!left && right) {
      return right;
    }
    if (!right && left) {
      return left;
    }
    if (left && right) {
      return root;
    }
    return nullptr;
  }
};
}  // namespace l236