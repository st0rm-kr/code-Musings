#include "232.cpp"
#include "225.cpp"
#include "20.cpp"
#include "1047.cpp"
#include "150.cpp"
#include "239.cpp"
#include "347.cpp"
#include "gtest/gtest.h"

TEST(Stack, TEST232) {
  l232::MyQueue l232;

  l232.push(1);
  l232.push(2);
  EXPECT_EQ(l232.peek(), 1);
  EXPECT_EQ(l232.pop(), 1);
  EXPECT_FALSE(l232.empty());
}

TEST(Queue, TEST225) {
  l225::MyStack l225;

  l225.push(1);
  l225.push(2);
  EXPECT_EQ(l225.top(), 2);
  EXPECT_EQ(l225.pop(), 2);
  EXPECT_FALSE(l225.empty());
}

TEST(Stack, TEST20) {
  l20::Solution l20;

  EXPECT_TRUE(l20.isValid("()"));
  EXPECT_FALSE(l20.isValid("((("));
  EXPECT_TRUE(l20.isValid("({[]})"));
}

TEST(Stack, TEST1047) {
  l1047::Solution l1047;

  EXPECT_EQ(l1047.removeDuplicates("abbaca"), "ca");
  EXPECT_EQ(l1047.removeDuplicates("azxxzy"), "ay");
}

TEST(Stack, TEST150) {
  l150::Solution l150;

  std::vector<std::string> case1 = {"2", "1", "+", "3", "*"};
  std::vector<std::string> case2 = {"4", "13", "5", "/", "+"};
  std::vector<std::string> case3 = {"10", "6", "9",  "3", "+", "-11", "*",
                                    "/",  "*", "17", "+", "5", "+"};

  EXPECT_EQ(l150.evalRPN(case1), 9);
  EXPECT_EQ(l150.evalRPN(case2), 6);
  EXPECT_EQ(l150.evalRPN(case3), 22);
}

TEST(Queue, TEST239) {
  l239::Solution l239;

  std::vector<int> case1 = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<int> ans1 = {3, 3, 5, 5, 6, 7};
  std::vector<int> case2 = {1, 3, 1, 2, 0, 5};
  std::vector<int> ans2 = {3, 3, 2, 5};

  EXPECT_EQ(l239.maxSlidingWindow(case1, 3), ans1);
  EXPECT_EQ(l239.maxSlidingWindow(case2, 3), ans2);
}

TEST(Queue, TEST347) {
  l347::Solution l347;

  std::vector<int> case1 = {1, 1, 1, 2, 2, 3};
  std::vector<int> ans1 = {1, 2};

  EXPECT_EQ(l347.topKFrequent(case1, 2), ans1);
}