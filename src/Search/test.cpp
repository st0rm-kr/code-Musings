#include "77.cpp"
#include "gtest/gtest.h"

TEST(Search, TEST77) {
  l77::Solution l77;

  std::vector<std::vector<int>> ans = {
      {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
  };
  EXPECT_EQ(l77.combine(4, 2), ans);
}