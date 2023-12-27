#include "203.cpp"
#include "707.cpp"
#include "206.cpp"
#include "24.cpp"
#include "19.cpp"
#include "160.cpp"
#include "142.cpp"
#include "gtest/gtest.h"

ListNode* GenerateList(const std::vector<int> &container) {
  if (container.empty()) return nullptr;
  
  ListNode *head = new ListNode();
  ListNode *p = head;

  for (auto x : container) {
    p->next = new ListNode(x);
    p = p->next;
  }
  auto res = head->next;
  delete head;
  return res;
}

auto Checker(ListNode *p, ListNode *q) {
  while (p && q) {
    if (p->val != q->val)
      return false;
    p = p->next;
    q = q->next;
  }
  if (p || q)
    return false;
  return true;
}

void CollectGarbage(ListNode *head) {
  ListNode *p = head;
  while (p) {
    auto q = p->next;
    delete p;
    p = q;
  }
}

TEST(EraseElements, TEST203) {
  auto list1 = GenerateList({1, 2, 6, 3, 4, 5, 6});
  auto list1_ = GenerateList({1, 2, 3, 4, 5});
  auto list2 = GenerateList({});
  auto list2_ = GenerateList({});
  auto list3 = GenerateList({7, 7, 7, 7});
  auto list3_ = GenerateList({});

  l203::Solution l203;
  EXPECT_TRUE(Checker(list1 = l203.removeElements(list1, 6), list1_));
  EXPECT_TRUE(Checker(list2 = l203.removeElements(list2, 1), list2_));
  EXPECT_TRUE(Checker(list3 = l203.removeElements(list3, 7), list3_));

  CollectGarbage(list1);
  CollectGarbage(list1_);
  CollectGarbage(list2);
  CollectGarbage(list2_);
  CollectGarbage(list3);
  CollectGarbage(list3_);

}

TEST(DesignList, TEST707) {
  l707::MyLinkedList myList1;
  myList1.addAtHead(1);
  myList1.addAtTail(3);
  myList1.addAtIndex(1, 2);
  EXPECT_EQ(myList1.get(1), 2);
  myList1.deleteAtIndex(1);
  EXPECT_EQ(myList1.get(1), 3);
}

TEST(ReverseList, TEST206) {
  l206::Solution l206;
  auto list1 = GenerateList({1, 2, 3, 4, 5});
  auto list1_ = GenerateList({5, 4, 3, 2, 1});
  auto list2 = GenerateList({});
  auto list2_ = GenerateList({});
  EXPECT_TRUE(Checker(l206.reverseList(list1), list1_));
  EXPECT_TRUE(Checker(l206.reverseList(list2), list2_));

  CollectGarbage(list1);
  CollectGarbage(list1_);
  CollectGarbage(list2);
  CollectGarbage(list2_);
}

TEST(SwapList, TEST24) {
  l24::Solution l24;
  auto list1 = GenerateList({1, 2, 3, 4});
  auto list1_ = GenerateList({2, 1, 4, 3});
  auto list2 = GenerateList({});
  auto list2_ = GenerateList({});
  auto list3 = GenerateList({1});
  auto list3_ = GenerateList({1});
  EXPECT_TRUE(Checker(l24.swapPairs(list1), list1_));
  EXPECT_TRUE(Checker(l24.swapPairs(list2), list2_));
  EXPECT_TRUE(Checker(l24.swapPairs(list3), list3_));

  CollectGarbage(list1);
  CollectGarbage(list1_);
  CollectGarbage(list2);
  CollectGarbage(list2_);
  CollectGarbage(list3);
  CollectGarbage(list3_);
}

TEST(EraseElements, TEST19) {
  l19::Solution l19;
  auto list1 = GenerateList({1, 2, 3, 4, 5});
  auto list1_ = GenerateList({1, 2, 3, 5});
  auto list2 = GenerateList({1});
  auto list2_ = GenerateList({});
  auto list3 = GenerateList({1, 2});
  auto list3_ = GenerateList({1});

  EXPECT_TRUE(Checker(list1 = l19.removeNthFromEnd(list1, 2), list1_));
  EXPECT_TRUE(Checker(list2 = l19.removeNthFromEnd(list2, 1), list2_));
  EXPECT_TRUE(Checker(list3 = l19.removeNthFromEnd(list3, 1), list3_));

  CollectGarbage(list1);
  CollectGarbage(list1_);
  CollectGarbage(list2);
  CollectGarbage(list2_);
  CollectGarbage(list3);
  CollectGarbage(list3_);
}

TEST(IntersectNode, TEST160) {
  l160::Solution l160;
  auto list1 = GenerateList({4, 1, 8, 4, 5});
  auto list2 = new ListNode(5);
  list2->next = new ListNode(0);
  list2->next->next = new ListNode(1);
  list2->next->next->next = list1->next->next;

  EXPECT_EQ(l160.getIntersectionNode(list1, list2)->val, 8);

  CollectGarbage(list1);
  delete list2->next->next;
  delete list2->next;
  delete list2;
}

TEST(ListCycle, TEST142) {
  l142::Solution l142;

  auto list1 = GenerateList({3, 2, 0, -4});
  list1->next->next->next->next = list1->next;
  auto list2 = GenerateList({1, 2});
  list2->next->next = list2;
  auto list3 = GenerateList({1});

  EXPECT_EQ(l142.detectCycle(list1), list1->next);
  EXPECT_EQ(l142.detectCycle(list2), list2);
  EXPECT_EQ(l142.detectCycle(list3), nullptr);

  list1->next->next->next->next = nullptr;
  list2->next->next = nullptr;
  CollectGarbage(list1);
  CollectGarbage(list2);
}