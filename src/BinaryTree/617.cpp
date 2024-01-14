#include "treeNode.h"

namespace l617 {
class Solution {
 public:
  TreeNode *cloneTree(TreeNode *u) {
    if (u) {
      auto res = new TreeNode(u->val);
      res->left = cloneTree(u->left);
      res->right = cloneTree(u->right);
      return res;
    }
    return nullptr;
  }
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) {
      return cloneTree(root2);
    }
    if (root2 == nullptr) {
      return cloneTree(root1);
    }
    TreeNode* root = new TreeNode(root1->val + root2->val);
    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);
    return root;
  }
};
}  // namespace l617