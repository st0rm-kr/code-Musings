#include "27.cpp"
#include "gtest/gtest.h"
#include <unordered_map>

/**
 * @brief 用来检测两个无序数组是否相等
 * 
 * @tparam T 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
template <typename T>
auto check(const std::vector<T> &a, const std::vector<T> &b) -> bool {
  std::unordered_map<T, int> kv;
  for (const auto &x : a) {
    ++kv[x];
  }
  for (const auto &x : b) {
    --kv[x];
  }
  for (auto &[_, v] : kv) {
    if (v != 0) {
      return false;
    }
  }
  return true;
}

TEST(DoublePointer, TEST27) {
  l27::Solution l27;

  std::vector<int> case1 = {3, 2, 2, 3};
  std::vector<int> ans1 = {2, 2};
  std::vector<int> case2 = {0, 1, 2, 2, 3, 0, 4, 2};
  std::vector<int> ans2 = {0, 1, 4, 0, 3};

  l27.removeElement(case1, 3);
  l27.removeElement(case2, 2);

  EXPECT_TRUE(check(case1, ans1));
  EXPECT_TRUE(check(case2, ans2));
}