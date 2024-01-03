#include "232.cpp"
#include "225.cpp"
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