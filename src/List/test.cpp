#include "203.cpp"
#include "707.cpp"
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

TEST(EraseElements, TEST203) {
  auto list1 = GenerateList({1, 2, 6, 3, 4, 5, 6});
  auto list1_ = GenerateList({1, 2, 3, 4, 5});
  auto list2 = GenerateList({});
  auto list2_ = GenerateList({});
  auto list3 = GenerateList({7, 7, 7, 7});
  auto list3_ = GenerateList({});

  l203::Solution l203;
  EXPECT_TRUE(Checker(l203.removeElements(list1, 6), list1_));
  EXPECT_TRUE(Checker(l203.removeElements(list2, 1), list2_));
  EXPECT_TRUE(Checker(l203.removeElements(list3, 7), list3_));
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