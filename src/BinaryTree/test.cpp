#include "treeNode.h"
#include "gtest/gtest.h"
#include "226.cpp"
#include "101.cpp"
#include "104.cpp"
#include "111.cpp"
#include <queue>

// 将二叉树平坦化成一维数组
auto flatten(TreeNode *root) -> std::vector<int> {
  if (root == nullptr) {
    return {};
  }
  
  std::queue<TreeNode*> q;
  std::vector<int> res;

  q.emplace(root);
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    res.emplace_back(t->val);

    if (t->left) {
      q.emplace(t->left);
    }
    if (t->right) {
      q.emplace(t->right);
    }
  }
  return res;
}

void CollectGarbage(TreeNode *root) {
  if (root) {
    CollectGarbage(root->left);
    CollectGarbage(root->right);
    delete root;
  }
}

TEST(BinaryTree, TEST226) {
  l226::Solution l226;

  auto *tree1 = new TreeNode(4);
  tree1->left = new TreeNode(2);
  tree1->right = new TreeNode(7);
  tree1->left->left = new TreeNode(1);
  tree1->left->right = new TreeNode(3);
  tree1->right->left = new TreeNode(6);
  tree1->right->right = new TreeNode(9);

  std::vector<int> ans1 = {4, 7, 2, 9, 6, 3, 1};
  l226.invertTree(tree1);
  EXPECT_EQ(flatten(tree1), ans1);

  CollectGarbage(tree1);
}

TEST(BinaryTree, TEST101) {
  l101::Solution l101;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(2);
  tree->left->left = new TreeNode(3);
  tree->left->right = new TreeNode(4);
  tree->right->left = new TreeNode(4);
  tree->right->right = new TreeNode(3);

  EXPECT_TRUE(l101.isSymmetric(tree));
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST104) {
  l104::Solution l104;

  auto *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);

  EXPECT_EQ(l104.maxDepth(tree), 3);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST111) {
  l111::Solution l111;

  auto *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);

  EXPECT_EQ(l111.minDepth(tree), 2);
  CollectGarbage(tree);
}