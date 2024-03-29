#include "treeNode.h"

namespace l669 {
class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root) {
      if (root->val < low) {
        return trimBST(root->right, low, high);
      }
      if (root->val > high) {
        return trimBST(root->left, low, high);
      }
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
    }
    return root;
  }
};
}  // namespace l669