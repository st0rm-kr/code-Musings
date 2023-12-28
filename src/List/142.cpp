#include "ListNode.h"

namespace l142 {
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast) {
      slow = slow->next;
      if (!fast->next)
        return nullptr;
      fast = fast->next->next;
      if (fast == slow) {
        ListNode *p = head;
        while (p != slow) {
          p = p->next;
          slow = slow->next;
        }
        return p;
      }
    }
    return nullptr;
  }
};
}  // namespace l142