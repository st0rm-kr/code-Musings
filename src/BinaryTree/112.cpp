#include "treeNode.h"

namespace l112 {
class Solution {
 public:
  bool dfs(TreeNode *u, int sum, int targetSum) {
    if (u) {
      sum += u->val;
      if (!u->left && !u->right) {
        return sum == targetSum;
      }
      return dfs(u->left, sum, targetSum) | dfs(u->right, sum, targetSum);
    }
    return false;
  }
  bool hasPathSum(TreeNode* root, int targetSum) {
    return dfs(root, 0, targetSum);
  }
};
}  // namespace l112