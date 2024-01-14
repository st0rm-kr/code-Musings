#include "treeNode.h"

namespace l700 {
class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root) {
      if (root->val == val) {
        return root;
      }
      if (root->val > val) {
        return searchBST(root->left, val);
      }
      if (root->val < val) {
        return searchBST(root->right, val);
      }
    }
    return nullptr;
  }
};
}  // namespace l700