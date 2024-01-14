#include "treeNode.h"

namespace l450 {
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root) {
      if (root->val == key) {
        if (!root->left && !root->right) {
          delete root;
          root = nullptr;
        } else if (!root->left) {
          auto* t = root;
          root = root->right;
          delete t;
        } else if (!root->right) {
          auto* t = root;
          root = root->left;
          delete t;
        } else {
          auto* u = root->right;
          while (u->left) {
            u = u->left;
          }
          u->left = root->left;
          auto* t = root;
          root = root->right;
          delete t;
        }
      } else {
        if (root->val > key) {
          root->left = deleteNode(root->left, key);
        } else {
          root->right = deleteNode(root->right, key);
        }
      }
    }
    return root;
  }
};
}  // namespace l450