#include "treeNode.h"
#include <algorithm>

namespace l226 {
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root) {
      invertTree(root->left);
      invertTree(root->right);
      std::swap(root->left, root->right);
    }
    return root;
  }
};
}  // namespace l226