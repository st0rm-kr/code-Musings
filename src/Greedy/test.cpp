#include "376.cpp"
#include "455.cpp"
#include <gtest/gtest.h>

TEST(Greedy, TEST455) {
  l455::Solution l455;

  std::vector<int> g = {1, 2, 3};
  std::vector<int> s = {1, 1};
  EXPECT_EQ(l455.findContentChildren(g, s), 1);
}

TEST(Greedy, TEST376) {
  l376::Solution l376;

  std::vector<int> case1 = {1, 7, 4, 9, 2, 5};
  std::vector<int> case2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  std::vector<int> case3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_EQ(l376.wiggleMaxLength(case1), 6);
  EXPECT_EQ(l376.wiggleMaxLength(case2), 7);
  EXPECT_EQ(l376.wiggleMaxLength(case3), 2);
}