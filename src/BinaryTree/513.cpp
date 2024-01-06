#include "treeNode.h"
#include <queue>

namespace l513 {
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int res{0};
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto size = q.size();
      res = q.front()->val;
      while (size--) {
        auto t = q.front();
        q.pop();
        if (t->left) {
          q.push(t->left);
        }
        if (t->right) {
          q.push(t->right);
        }
      }
    }
    return res;
  }
};
}  // namespace l513