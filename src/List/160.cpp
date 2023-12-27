#include "ListNode.h"

namespace l160 {
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    if (p != q && (!p || !q))
      return nullptr;

    while (p != q) {
      p ? p = p->next : p = headB;
      q ? q = q->next : q = headA;
    }
    return p;
  }
};
}