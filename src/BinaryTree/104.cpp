#include "treeNode.h"
#include <algorithm>

namespace l104 {
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root) {
      return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
    return 0;
  }
};
}  // namespace l104