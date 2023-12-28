#include "ListNode.h"

namespace l24 {
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    if (!head->next) {
      return head;
    }

    ListNode* p = head;
    ListNode *dummy = new ListNode(), *t = dummy;

    while (p && p->next) {
      auto* q = p->next;
      p->next = q->next;
      t->next = q;
      t->next->next = p;
      p = p->next;
      t = t->next->next;
    }

    auto res = dummy->next;
    delete dummy;
    return res;
  }
};
}  // namespace l24