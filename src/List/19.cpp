#include "ListNode.h"

namespace l19 {
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode *fast = head, *slow = dummy;
    while (n--) fast = fast->next;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    auto t = slow->next;
    slow->next = t->next;
    delete t;
    auto res = dummy->next;
    delete dummy;
    return res;
  }
};
}  // namespace l19