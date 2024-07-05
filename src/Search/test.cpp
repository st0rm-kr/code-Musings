#include "131.cpp"
#include "17.cpp"
#include "216.cpp"
#include "332.cpp"
#include "37.cpp"
#include "39.cpp"
#include "40.cpp"
#include "46.cpp"
#include "47.cpp"
#include "491.cpp"
#include "51.cpp"
#include "77.cpp"
#include "78.cpp"
#include "90.cpp"
#include "93.cpp"
#include "gtest/gtest.h"
#include <vector>

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

TEST(Search, TEST491) {
  l491::Solution l491;

  // [4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]
  std::vector<std::vector<int>> ans{{4, 6},    {4, 6, 7}, {4, 6, 7, 7}, {4, 7},
                                    {4, 7, 7}, {6, 7},    {6, 7, 7},    {7, 7}};
  std::vector<int> case1{4, 6, 7, 7};
  EXPECT_EQ(ans, l491.findSubsequences(case1));
}

TEST(Search, TEST39) {
  l39::Solution l39;

  std::vector<std::vector<int>> ans{{2, 2, 3}, {7}};
  std::vector<int> candidates{2, 3, 6, 7};
  EXPECT_EQ(l39.combinationSum(candidates, 7), ans);
}

TEST(Search, TEST131) {
  l131::Solution l131;

  std::vector<std::vector<std::string>> ans{{"a", "a", "b"}, {"aa", "b"}};
  EXPECT_EQ(l131.partition("aab"), ans);
}

TEST(Search, TEST93) {
  l93::Solution l93;

  std::vector<std::string> ans{{"255.255.11.135"}, {"255.255.111.35"}};
  EXPECT_EQ(l93.restoreIpAddresses("25525511135"), ans);
}

TEST(Search, TEST46) {
  l46::Solution l46;

  std::vector<int> case1{1, 2, 3};
  std::vector<std::vector<int>> ans1{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                     {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

  EXPECT_EQ(l46.permute(case1), ans1);
}

TEST(Search, TEST40) {
  l40::Solution l40;

  std::vector<int> case1 = {10, 1, 2, 7, 6, 1, 5};
  std::vector<std::vector<int>> res = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  EXPECT_EQ(l40.combinationSum2(case1, 8), res);
}

TEST(Search, TEST78) {
  l78::Solution l78;

  std::vector<int> case1 = {1, 2, 3};
  std::vector<std::vector<int>> ans1 = {{},  {1},    {2},    {1, 2},
                                        {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  EXPECT_EQ(l78.subsets(case1), ans1);
}

TEST(Search, TEST47) {
  l47::Solution l47;

  std::vector<int> case1 = {1, 1, 2};
  std::vector<std::vector<int>> ans1 = {
      {1, 1, 2},
      {1, 2, 1},
      {2, 1, 1},
  };
  EXPECT_EQ(l47.permuteUnique(case1), ans1);
}

TEST(Search, TEST90) {
  l90::Solution l90;

  std::vector<int> case1 = {1, 2, 2};
  std::vector<std::vector<int>> ans1 = {
      {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2},
  };
  EXPECT_EQ(l90.subsetsWithDup(case1), ans1);
}

TEST(Search, TEST332) {
  l332::Solution l332;

  std::vector<std::vector<std::string>> case1 = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  std::vector<std::string> ans1 = {"JFK", "MUC", "LHR", "SFO", "SJC"};
  EXPECT_EQ(l332.findItinerary(case1), ans1);
}

TEST(Search, TEST51) {
  l51::Solution l51;
  int n = 4;
  std::vector<std::vector<std::string>> ans1 = {
      {".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
  EXPECT_EQ(l51.solveNQueens(n), ans1);
}

TEST(Search, TEST37) {
  l37::Solution l37;
  std::vector<std::vector<char>> board = {
      {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
       {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
       {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
       {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
       {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
       {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
       {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
       {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
       {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};
  std::vector<std::vector<char>> ans = {
      {{ '5', '3', '4', '6', '7', '8', '9', '1', '2' },
       { '6', '7', '2', '1', '9', '5', '3', '4', '8' },
       { '1', '9', '8', '3', '4', '2', '5', '6', '7' },
       { '8', '5', '9', '7', '6', '1', '4', '2', '3' },
       { '4', '2', '6', '8', '5', '3', '7', '9', '1' },
       { '7', '1', '3', '9', '2', '4', '8', '5', '6' },
       { '9', '6', '1', '5', '3', '7', '2', '8', '4' },
       { '2', '8', '7', '4', '1', '9', '6', '3', '5' },
       { '3', '4', '5', '2', '8', '6', '1', '7', '9' }}};
  l37.solveSudoku(board);
  EXPECT_EQ(board, ans);
}