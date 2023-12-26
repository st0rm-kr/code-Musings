namespace l707 {

// 循环双向链表
class MyLinkedList {
public:
  MyLinkedList() {
    head = new ListNode{-1};
    head->next = head;
    head->prev = head;
  }

  int get(int index) {
    if (index < size) {
      if (index == 0) {
        return head->next->val;
      } else if (index == size - 1) {
        return head->prev->val;
      } else {
        ListNode *p = head->next;
        while (index--) {
          p = p->next;
        }
        return p->val;
      }
    }
    return -1;
  }

  void addAtHead(int val) {
    ListNode *t = new ListNode{val};

    t->next = head->next;
    t->prev = head->next->prev;
    head->next->prev = t;
    head->next = t;
    ++size;
  }

  void addAtTail(int val) {
    ListNode *t = new ListNode{val};

    t->prev = head->prev;
    t->next = head->prev->next;
    head->prev->next = t;
    head->prev = t;
    ++size;
  }

  void addAtIndex(int index, int val) {
    if (index == size) {
      addAtTail(val);
    } else if (index < size) {
      ListNode *p = head->next;
      while (index--) {
        p = p->next;
      }

      ListNode *t = new ListNode{val};
      t->next = p;
      t->prev = p->prev;
      p->prev->next = t;
      t->next = p;
      p->prev = t;
      ++size;
    }
  }

  void deleteAtIndex(int index) {
    if (index < size) {
      ListNode *p = head->next;
      while (index--) {
        p = p->next;
      }

      p->prev->next = p->next;
      p->next->prev = p->prev;
      delete p;
      --size;
    }
  }

private:
  struct ListNode {
    int val;
    ListNode *next{nullptr};
    ListNode *prev{nullptr};
  };

  ListNode *head;
  unsigned int size{0};
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
}