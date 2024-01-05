#include "treeNode.h"
#include <string>
#include <vector>

namespace l257 {
class Solution {
public:
  void dfs(TreeNode *root, std::string path,
           std::vector<std::string> &result) {
    if (root) {
      if (path.empty()) {
        path += std::to_string(root->val);
      } else {
        path += "->" + std::to_string(root->val);
      }
      if (!root->left && !root->right) {
        result.push_back(path);
      }
      dfs(root->left, path, result);
      dfs(root->right, path, result);
      }
  }
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    if (root) {
      std::vector<std::string> result;
      std::string path;
      dfs(root, path, result);
      return result;
    }
    return {};
  }
};
} // namespace l257