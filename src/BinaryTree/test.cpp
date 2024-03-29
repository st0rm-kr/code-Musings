#include "treeNode.h"
#include "gtest/gtest.h"
#include "226.cpp"
#include "101.cpp"
#include "104.cpp"
#include "111.cpp"
#include "222.cpp"
#include "110.cpp"
#include "257.cpp"
#include "404.cpp"
#include "513.cpp"
#include "112.cpp"
#include "106.cpp"
#include "654.cpp"
#include "617.cpp"
#include "700.cpp"
#include "98.cpp"
#include "530.cpp"
#include "501.cpp"
#include "236.cpp"
#include "235.cpp"
#include "701.cpp"
#include "669.cpp"
#include "538.cpp"
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

TEST(BinaryTree, TEST222) {
  l222::Solution l222;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->left->left = new TreeNode(4);
  tree->left->right = new TreeNode(5);

  EXPECT_EQ(l222.countNodes(tree), 5);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST110) {
  l110::Solution l110;

  auto *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  EXPECT_TRUE(l110.isBalanced(tree));
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST257) {
  l257::Solution l257;

  auto *tree = new TreeNode(1);
  EXPECT_EQ(l257.binaryTreePaths(tree), std::vector<std::string>({"1"}));
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST404) {
  l404::Solution l404;

  auto *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  EXPECT_EQ(l404.sumOfLeftLeaves(tree), 24);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST513) {
  l513::Solution l513;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->left->left = new TreeNode(4);
  tree->right = new TreeNode(3);
  tree->right->left = new TreeNode(5);
  tree->right->left->left = new TreeNode(7);
  tree->right->right = new TreeNode(6);

  EXPECT_EQ(l513.findBottomLeftValue(tree), 7);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST112) {
  l112::Solution l112;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  EXPECT_FALSE(l112.hasPathSum(tree, 5));
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST106) {
  l106::Solution l106;

  std::vector<int> inorder{9, 3, 15, 20, 7};
  std::vector<int> postorder{9, 15, 7, 20, 3};
  auto *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  auto ans = flatten(tree);

  auto res = l106.buildTree(inorder, postorder);
  EXPECT_EQ(ans, flatten(res));

  CollectGarbage(res);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST654) {
  l654::Solution l654;

  std::vector<int> nums{3, 2, 1};
  auto *tree = new TreeNode(3);
  tree->right = new TreeNode(2);
  tree->right->right = new TreeNode(1);
  auto case1 = flatten(tree);
  auto res = l654.build(nums, 0, 2);

  EXPECT_EQ(case1, flatten(res));
  CollectGarbage(res);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST617) {
  l617::Solution l617;

  auto *tree1 = new TreeNode(1);
  tree1->left = new TreeNode(3);
  tree1->left->left = new TreeNode(5);
  tree1->right = new TreeNode(2);

  auto *tree2 = new TreeNode(2);
  tree2->left = new TreeNode(1);
  tree2->left->right = new TreeNode(4);
  tree2->right = new TreeNode(3);
  tree2->right->right = new TreeNode(7);

  std::vector<int> ans{3, 4, 5, 5, 4, 7};
  auto res = l617.mergeTrees(tree1, tree2);
  EXPECT_EQ(ans, flatten(res));

  CollectGarbage(tree1);
  CollectGarbage(tree2);
  CollectGarbage(res);
}

TEST(BinaryTree, TEST700) {
  l700::Solution l700;

  auto *tree = new TreeNode(4);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(7);
  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);

  EXPECT_EQ(l700.searchBST(tree, 2)->val, 2);
}

TEST(BinaryTree, TEST98) {
  l98::Solution l98;

  auto *tree = new TreeNode(5);
  tree->left = new TreeNode(4);
  tree->right = new TreeNode(6);
  tree->right->left = new TreeNode(3);
  tree->right->right = new TreeNode(7);

  EXPECT_FALSE(l98.isValidBST(tree));
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST530) {
  l530::Solution l530;

  auto *tree = new TreeNode(4);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(6);
  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);

  EXPECT_EQ(l530.getMinimumDifference(tree), 1);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST501) {
  l501::Solution l501;

  auto *tree = new TreeNode(1);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(2);

  std::vector<int> ans{2};
  EXPECT_EQ(l501.findMode(tree), ans);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST236) {
  l236::Solution l236;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(2);

  EXPECT_EQ(tree->val, l236.lowestCommonAncestor(tree, tree, tree->left)->val);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST235) {
  l235::Solution l235;

  auto *tree = new TreeNode(2);
  tree->left = new TreeNode(1);
  tree->right = new TreeNode(3);

  EXPECT_EQ(tree->val,
            l235.lowestCommonAncestor(tree, tree->left, tree->right)->val);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST701) {
  l701::Solution l701;

  auto *tree = new TreeNode(2);
  l701.insertIntoBST(tree, 1);

  auto res = flatten(tree);
  std::vector<int> ans = {2, 1};
  EXPECT_EQ(ans, res);
  CollectGarbage(tree);
}

TEST(BinaryTree, TEST669) {
  l669::Solution l669;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(0);
  auto *t = tree->left;
  tree->right = new TreeNode(2);
  std::vector<int> ans = {1, 2};
  auto res = l669.trimBST(tree, 1, 2);
  EXPECT_EQ(ans, flatten(res));
  CollectGarbage(tree);
  delete t;
}

TEST(BinaryTree, TEST538) {
  l538::Solution l538;

  auto *tree = new TreeNode(1);
  tree->left = new TreeNode(0);
  tree->right = new TreeNode(2);
  std::vector<int> ans{3, 3, 2};
  EXPECT_EQ(flatten(l538.convertBST(tree)), ans);
  CollectGarbage(tree);
}