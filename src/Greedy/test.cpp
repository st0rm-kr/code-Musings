#include "376.cpp"
#include "455.cpp"
#include "53.cpp"
#include "122.cpp"
#include "55.cpp"
#include "45.cpp"
#include "1005.cpp"
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

TEST(Greedy, TEST53) {
  l53::Solution l53;

  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(l53.maxSubArray(nums), 6);
}

TEST(Greedy, TEST122) {
  l122::Solution l122;

  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(l122.maxProfit(prices), 7);
}

TEST(Greedy, TEST55) {
  l55::Solution l55;

  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(l55.canJump(nums), true);
}

TEST(Greedy, TEST45) {
  l45::Solution l45;

  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(l45.jump(nums), 2);
}

TEST(Greedy, TEST1005) {
  l1005::Solution l1005;
  std::vector<int> case1 = {2, -3, -1, 5, -4};
  EXPECT_EQ(l1005.largestSumAfterKNegations(case1, 3), 13);
}