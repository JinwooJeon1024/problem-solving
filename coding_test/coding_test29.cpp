#include<bits/stdc++.h>
using namespace std;

class MyBST {
private:
    struct Node {
      Node* left = nullptr; 
      Node* right = nullptr;
      int value;

      Node(int v): value(v) {}
    };

    Node* _head = nullptr;

    bool insert(int value, Node*& head) {
      if(_head == nullptr) {
        _head = head;
        head->value = value;
        return true;
      }

      if(value == _head->value) return false;
      else if(value < _head->value) {
        return insert(value, _head->left);
      }
      else if(value > _head->value) {
        return insert(value, _head->right);
      }
    }

    bool contains(int value, Node* head) const {
      if(head == nullptr) return false;
      return head->value == value || contains(value, head->left) || contains(value, head->right);

    }

    bool erase(int value, Node*& head) {
      if(head == nullptr) return false;

      if(head->value == value) {
        if(!head->right && !head->left) {
          delete head;
          head = nullptr;
          return true;
        } 
        else if(!head->right) {
          _head = head->right;
          delete head;
          head = nullptr;
          return true;
        }
        else if(!head->left) {
          _head = head->left;
          delete head;
          head = nullptr;
          return true;
        }
        else {

        }
      }
      else if(head->value < value) {
        return erase(value, head->right);
      }
      else if(head->value > value) {
        return erase(value, head->left);
      }
    }

    vector<int> inorder(Node* head) const {
      vector<int> ret;
      if(head == nullptr) return ret;

      for(auto& cur: inorder(head->left)) {
        ret.push_back(cur);
      }

      ret.push_back(head->value);

      for(auto& cur: inorder(head->right)) {
        ret.push_back(cur);
      }

      return ret;
    }

public:
    MyBST();

    bool insert(int value) {
      return insert(value, _head);
    }
    bool contains(int value) const {
      return contains(value, _head);
    }
    bool erase(int value) {
      return erase(value, _head);
    }

    vector<int> inorder() const {
      return inorder(_head);
    }
};