#include "treeNode.h"

namespace l538 {
class Solution {
 public:
  TreeNode* pre{nullptr};
  TreeNode* convertBST(TreeNode* root) {
    if (root) {
      convertBST(root->right);
      if (pre) {
        root->val += pre->val;
      }
      pre = root;
      convertBST(root->left);
    }
    return root;
  }
};
}  // namespace l538