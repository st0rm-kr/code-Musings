#include "ListNode.h"

namespace l203 {

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *p = dummy;

    while (p->next) {
      if (p->next->val == val) {
        auto t = p->next;
        p->next = t->next;
        delete t;
      } else p = p->next;
    }

    p = dummy->next;
    delete dummy;
    return p;
  }
};
} // namespace l203