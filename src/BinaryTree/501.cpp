#include "treeNode.h"
#include <vector>

namespace l501 {
class Solution {
public:
  TreeNode *pre{nullptr};
  std::vector<int> result{};
  int cnt{0};
  int maxCnt{0};
  void helper(TreeNode *u) {
    if (u) {
      helper(u->left);
      if (!pre) {
        cnt = 1;
      } else if (pre->val == u->val) {
        ++cnt;
      } else {
        cnt = 1;
      }
      pre = u;
      if (cnt == maxCnt) {
        result.emplace_back(u->val);
      }
      if (cnt > maxCnt) {
        maxCnt = cnt;
        result.clear();
        result.emplace_back(u->val);
      }
      helper(u->right);
    }
  }

  std::vector<int> findMode(TreeNode *root) {
    helper(root);
    return result;
  }
};
}  // namespace l501