#include "ListNode.h"

namespace l206 {
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* dummy = new ListNode;

    ListNode* p = head;
    while (p) {
      auto t = p->next;
      p->next = dummy->next;
      dummy->next = p;
      p = t;
    }
    auto res = dummy->next;
    delete dummy;
    return res;
  }
};
}  // namespace l206