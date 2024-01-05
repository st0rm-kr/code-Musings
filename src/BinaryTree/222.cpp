#include "treeNode.h"

namespace l222 {
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root) {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
    return 0;
  }
};
}  // namespace l222