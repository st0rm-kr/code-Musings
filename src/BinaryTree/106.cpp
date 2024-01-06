#include "treeNode.h"
#include <vector>
#include <algorithm>

namespace l106 {
class Solution {
 public:
  TreeNode* build(std::vector<int>& inorder, int l1, int r1,
                  std::vector<int>& postorder, int l2, int r2) {
    if (l1 > r1 || l2 > r2) {
      return nullptr;
    }
    // 后序遍历的最后一个必然是根
    auto root = new TreeNode(postorder[r2]);
    // 找到这个跟在中序中的位置
    auto pos =
        std::find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
    root->left =
        build(inorder, l1, pos - 1, postorder, l2, l2 + (pos - 1 - l1));
    root->right = build(inorder, pos + 1, r1, postorder, l2 + pos - l1, r2 - 1);
    return root;
  }
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    auto res = build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
    return res;
  }
};
}  // namespace l106