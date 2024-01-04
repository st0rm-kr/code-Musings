#include "treeNode.h"
#include <algorithm>

namespace l111 {

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root) {
      int res = 1e8;
      if (root->left) {
        res = std::min(res, minDepth(root->left));
      }
      if (root->right) {
        res = std::min(res, minDepth(root->right));
      }
      if (res == 1e8) {
        return 1;
      }
      return res + 1;
    }
    return 0;
  }
};
}  // namespace l111