#include "344.cpp"
#include "gtest/gtest.h"

TEST(String, TEST344) {
  l344::Solution l344;
  std::vector<char> case1 = {'h', 'e', 'l', 'l', 'o'};
  std::vector<char> case2 = {'h', 'a', 'n', 'n', 'a', 'h'};
  std::vector<char> ans1 = {'o', 'l', 'l', 'e', 'h'};
  std::vector<char> ans2 = {'h', 'a', 'n', 'n', 'a', 'h'};

  l344.reverseString(case1);
  l344.reverseString(case2);

  EXPECT_EQ(case1, ans1);
  EXPECT_EQ(case2, ans2);
}