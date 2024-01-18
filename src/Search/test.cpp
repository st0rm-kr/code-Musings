#include "77.cpp"
#include "216.cpp"
#include "17.cpp"
#include "39.cpp"
#include "gtest/gtest.h"

TEST(Search, TEST77) {
  l77::Solution l77;

  std::vector<std::vector<int>> ans{
      {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
  };
  EXPECT_EQ(l77.combine(4, 2), ans);
}

TEST(Search, TEST216) {
  l216::Solution l216;

  std::vector<std::vector<int>> ans{{1, 2, 4}};
  EXPECT_EQ(l216.combinationSum3(3, 7), ans);
}

TEST(Search, TEST17) {
  l17::Solution l17;

  std::vector<std::string> ans{{"ad"}, {"ae"}, {"af"}, {"bd"}, {"be"},
                               {"bf"}, {"cd"}, {"ce"}, {"cf"}};
  EXPECT_EQ(ans, l17.letterCombinations("23"));
}

TEST(Search, TEST39) {
  l39::Solution l39;

  std::vector<std::vector<int>> ans{{2, 2, 3}, {7}};
  std::vector<int> candidates{2, 3, 6, 7};
  EXPECT_EQ(l39.combinationSum(candidates, 7), ans);
}