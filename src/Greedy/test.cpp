#include "455.cpp"
#include <gtest/gtest.h>

TEST(Greedy, TEST455) {
  l455::Solution l455;

  std::vector<int> g = {1, 2, 3};
  std::vector<int> s = {1, 1};
  EXPECT_EQ(l455.findContentChildren(g, s), 1);
}