#include <vector>

#include "209.cpp"
#include "34.cpp"
#include "35.cpp"
#include "367.cpp"
#include "59.cpp"
#include "69.cpp"
#include "gtest/gtest.h"

TEST(BinarySearch, Test35) {
  L35::Solution l35;
  std::vector<int> vec{1, 3, 5, 6};
  EXPECT_EQ(l35.searchInsert(vec, 5), 2);
  EXPECT_EQ(l35.searchInsert(vec, 2), 1);
  EXPECT_EQ(l35.searchInsert(vec, 7), 4);
}

TEST(BinarySearch, TEST34) {
  L34::Solution l34;
  std::vector<int> vec{5, 7, 7, 8, 8, 10};
  std::vector<int> empty;
  EXPECT_EQ(l34.searchRange(vec, 8), std::vector<int>({3, 4}));
  EXPECT_EQ(l34.searchRange(vec, 6), std::vector<int>({-1, -1}));
  EXPECT_EQ(l34.searchRange(empty, 0), std::vector<int>({-1, -1}));
}

TEST(BinarySearch, TEST69) {
  L69::Solution l69;
  EXPECT_EQ(l69.mySqrt(4), 2);
  EXPECT_EQ(l69.mySqrt(100), 10);
  EXPECT_EQ(l69.mySqrt(25), 5);
}

TEST(BinarySearch, TEST367) {
  l367::Solution l367;
  EXPECT_TRUE(l367.isPerfectSquare(25));
  EXPECT_TRUE(l367.isPerfectSquare(16));
  EXPECT_FALSE(l367.isPerfectSquare(14));
  EXPECT_FALSE(l367.isPerfectSquare(5));
}

TEST(Other, TEST209) {
  l209::Solution l209;
  std::pair<int, vector<int>> case1 = {7, {2, 3, 1, 2, 4, 3}};
  std::pair<int, vector<int>> case2 = {4, {1, 4, 4}};
  std::pair<int, vector<int>> case3 = {11, {1, 1, 1, 1, 1, 1, 1, 1}};

  EXPECT_EQ(l209.minSubArrayLen(case1.first, case1.second), 2);
  EXPECT_EQ(l209.minSubArrayLen(case2.first, case2.second), 1);
  EXPECT_EQ(l209.minSubArrayLen(case3.first, case3.second), 0);

  EXPECT_EQ(l209.minSubArrayLen2(case1.first, case1.second), 2);
  EXPECT_EQ(l209.minSubArrayLen2(case2.first, case2.second), 1);
  EXPECT_EQ(l209.minSubArrayLen2(case3.first, case3.second), 0);
}

TEST(Other, TEST59) {
  l59::Solution l59;

  std::pair<int, vector<vector<int>>> case1 = {
      3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}};
  std::pair<int, vector<vector<int>>> case2 = {1, {{1}}};

  EXPECT_EQ(l59.generateMatrix(case1.first), case1.second);
  EXPECT_EQ(l59.generateMatrix(case2.first), case2.second);
}
