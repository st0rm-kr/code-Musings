#include "242.cpp"
#include "349.cpp"
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