#include "1.cpp"
#include "202.cpp"
#include "242.cpp"
#include "349.cpp"
#include "454.cpp"
#include "383.cpp"
#include "15.cpp"
#include "gtest/gtest.h"

TEST(HashMap, TEST242) {
  l242::Solution l242;
  EXPECT_TRUE(l242.isAnagram("anagram", "nagaram"));
  EXPECT_FALSE(l242.isAnagram("rat", "car"));
}

TEST(HashMap, TEST349) {
  l349::Solution l349;
  std::vector<int> v1 = {1, 2, 2, 1};
  std::vector<int> v2 = {2, 2};
  std::vector<int> res1 = {2};
  std::vector<int> v3 = {4, 9, 5};
  std::vector<int> v4 = {9, 4, 9, 8, 4};
  std::vector<int> res2 = {4, 9};
  EXPECT_EQ(l349.intersection(v1, v2), res1);
  EXPECT_EQ(l349.intersection(v3, v4), res2);
}

TEST(HashMap, TEST202) {
  l202::Solution l202;
  EXPECT_TRUE(l202.isHappy(19));
  EXPECT_FALSE(l202.isHappy(2));
}

TEST(HashMap, TEST1) {
  l1::Solution l1;
  std::vector<int> case1 = {2, 7, 11, 15};
  std::vector<int> case2 = {3, 2, 4};
  std::vector<int> case3 = {3, 3};
  EXPECT_EQ(l1.twoSum(case1, 9), std::vector<int>({0, 1}));
  EXPECT_EQ(l1.twoSum(case2, 6), std::vector<int>({1, 2}));
  EXPECT_EQ(l1.twoSum(case3, 6), std::vector<int>({0, 1}));
}

TEST(HashMap, TEST454) {
  l454::Solution l454;
  std::vector<int> a{1, 2};
  std::vector<int> b{-2, -1};
  std::vector<int> c{-1, 2};
  std::vector<int> d{0, 2};
  EXPECT_EQ(l454.fourSumCount(a, b, c, d), 2);
}

TEST(HashMap, TEST383) {
  l383::Solution l383;
  EXPECT_FALSE(l383.canConstruct("a", "b"));
  EXPECT_FALSE(l383.canConstruct("aa", "ab"));
  EXPECT_TRUE(l383.canConstruct("aa", "aab"));
}

TEST(HashMap, TEST15) {
  l15::Solution l15;
  std::vector<int> case1 = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> ans1 = {{-1, -1, 2}, {-1, 0, 1}};
  std::vector<int> case2 = {0, 1, 1};
  std::vector<std::vector<int>> ans2 = {};
  std::vector<int> case3 = {0, 0, 0};
  std::vector<std::vector<int>> ans3 = {{0, 0, 0}};
  EXPECT_EQ(l15.threeSum(case1), ans1);
  EXPECT_EQ(l15.threeSum(case2), ans2);
  EXPECT_EQ(l15.threeSum(case3), ans3);
}