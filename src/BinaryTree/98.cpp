#include "treeNode.h"
#include <algorithm>
#include <unordered_map>

namespace l98 {
class Solution {
public:
  TreeNode *pre{nullptr};
  // BST的中序遍历应该满足从小到大递增
  bool isValidBST(TreeNode *root) {
    if (root) {
      bool left = isValidBST(root->left);
      if (pre && pre->val >= root->val) {
        return false;
      }
      pre = root;
      bool right = isValidBST(root->right);
      return left && right;
    }
    return true;
  }
};
}  // namespace l98