#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;

  if(fast == nullptr) return false;

  while(fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow) return true;
  }

  return false;
}

ListNode* detectCycleStart(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;

  if(fast == nullptr) return nullptr;

  while(fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow) {
      ListNode* a = head;

      while(slow != a) {
        slow = slow->next;
        a = a->next;
      }

      return slow;
    }
  }

  return nullptr;
}