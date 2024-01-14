#include "treeNode.h"

namespace l235 {
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *res = root;
    while (res) {
      if (p->val < res->val && q->val < res->val) {
        res = res->left;
      } else if (p->val > res->val && q->val > res->val) {
        res = res->right;
      } else {
        break;
      }
    }
    return res;
  }
};
}  // namespace l235