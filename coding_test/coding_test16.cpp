#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList():
      head(nullptr), tail(nullptr) {

      }

    void pushFront(int value) {
      Node* newNode = new Node{value, nullptr};

      if(head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
      }

      newNode->next = head;
      head = newNode;

      return;
    }
    void pushBack(int value) {
      Node* newNode = new Node{value, nullptr};

      if(tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
      }

      tail->next = newNode;
      tail = newNode;

      return;
    }

    bool remove(int value) {
      Node* cur = head;
      Node* prev = nullptr;

      while(cur != nullptr) {
        if(cur->value == value) {
          if(prev == nullptr) {
            head = cur->next;
            if(tail == cur) 
              tail = nullptr;

            delete cur;
            return true;
          }

          if(cur == tail) {
            tail = prev;
          }

          prev->next = cur->next;
          delete cur;
          return true;
        }

        prev = cur;
        cur = cur->next;
      }

      return false;

    }

    bool contains(int value) {
      Node* cur = head;

      while(cur != nullptr) {
        if(cur->value == value) return true;
        cur = cur->next;
      }

      return false;
    }
};