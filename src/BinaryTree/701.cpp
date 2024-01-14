#include "treeNode.h"

namespace l701 {
class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      root = new TreeNode(val);
    }
    TreeNode *u = root;
    while (u->val != val) {
      if (u->val > val) {
        if (!u->left) {
          u->left = new TreeNode(val);
        }
        u = u->left;
      } else if (u->val < val) {
        if (!u->right) {
          u->right = new TreeNode(val);
        }
        u = u->right;
      }
    }
    return root;
  }
};
}  // namespace l701