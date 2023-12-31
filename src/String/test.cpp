#include "344.cpp"
#include "541.cpp"
#include "replace_string.cpp"
#include "151.cpp"
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

TEST(String, TEST541) {
  l541::Solution l541;

  EXPECT_EQ(l541.reverseStr("abcdefg", 2), "bacdfeg");
  EXPECT_EQ(l541.reverseStr("abcd", 2), "bacd");
}

TEST(String, TEST_REPLACE_STRING) {
  replace_string::Solution replacer;

  std::string case1 = "a5b";
  replacer.replaceString(case1);
  EXPECT_EQ(case1, "anumberb");
}

TEST(String, TEST151) {
  l151::Solution l151;

  EXPECT_EQ(l151.reverseWords("the sky is blue"), "blue is sky the");
  EXPECT_EQ(l151.reverseWords("  hello world  "), "world hello");
  EXPECT_EQ(l151.reverseWords("a good   example"), "example good a");
}