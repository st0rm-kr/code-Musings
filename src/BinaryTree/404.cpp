#include "treeNode.h"

namespace l404 {
class Solution {
 public:
  int res{0};

  void dfs(TreeNode *u, bool flag) {
    if (u) {
      if (flag && !u->left && !u->right) {
        res += u->val;
      }
      dfs(u->left, true);
      dfs(u->right, false);
    }
  }
  int sumOfLeftLeaves(TreeNode* root) {
    res = 0;
    dfs(root, false);
    return res;
  }
};
}  // namespace l404