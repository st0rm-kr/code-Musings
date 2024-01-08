#include "treeNode.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace l530 {
class Solution {
public:
  int res{0x3f3f3f3f};
  TreeNode *pre{nullptr};
  int getMinimumDifference(TreeNode *root) {
    if (root) {
      getMinimumDifference(root->left);
      if (pre) {
        res = std::min(res, abs(root->val - pre->val));
      }
      pre = root;
      getMinimumDifference(root->right);
    }
    return res;
  }
};
}  // namespace l530