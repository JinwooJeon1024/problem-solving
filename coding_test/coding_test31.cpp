#include <bits/stdc++.h>
using namespace std;

class MyBST {
private:
    struct Node {
      int value;
      Node* left = nullptr;
      Node* right = nullptr;

      Node(int v): 
        value(v) {}
    };

    Node* root;

    bool insert(int value, Node*& cur) {
      if(cur == nullptr) {
        Node* newNode = new Node(value);
        cur = newNode;

        return true;
      }

      if(cur->value == value) return false;
      else if(cur->value > value) return insert(value, cur->left);
      else return insert(value, cur->right);
    }

    bool contains(int value, Node* cur) const {
      if(cur == nullptr) return false;

      if(cur->value == value) return true;
      else if(cur->value > value) return contains(value, cur->left);
      else return contains(value, cur->right);
    }

    bool erase(int value, Node*& cur) {
      if(cur == nullptr) return false;

      if(cur->value == value) {
        auto lc = cur->left;
        auto rc = cur->right;

        if(lc && rc) {
          Node* successor = cur->right;
          while(successor->left != nullptr) {
            successor = successor->left;
          }

          cur->value = successor->value;
          return erase(successor->value, cur->right);
        } 
        else if(lc) {
          Node* old = cur;
          cur = lc;
          delete old;
          return true;
        }
        else if(rc) {
          Node* old = cur;
          cur = rc;
          delete old;
          return true;
        }
        else {
          delete cur;
          cur = nullptr;
          return true;
        }
      }
      else if(cur->value > value) return erase(value, cur->left);
      else return erase(value, cur->right);
    }

    void inorder(vector<int>& v, Node* cur) const {
      if(cur == nullptr) return;

      inorder(v, cur->left);
      v.push_back(cur->value);
      inorder(v, cur->right);
    }

public:
    MyBST():
      root(nullptr) {}
    bool insert(int value) {
      return insert(value, root);
    }
    bool contains(int value) const {
      return contains(value, root);
    }
    bool erase(int value) {
      return erase(value, root);
    }
    vector<int> inorder() const {
      vector<int> ret;

      inorder(ret, root);

      return ret;
    }
};

int main() {
    MyBST bst;

    // Test 1: 빈 BST
    assert(!bst.contains(5));
    assert(!bst.erase(5));
    assert(bst.inorder().empty());

    // Test 2: 삽입
    assert(bst.insert(5));
    assert(bst.insert(3));
    assert(bst.insert(7));
    assert(bst.insert(2));
    assert(bst.insert(4));
    assert(bst.insert(6));
    assert(bst.insert(8));

    // Test 3: 검색 및 중복 삽입
    assert(bst.contains(4));
    assert(bst.contains(7));
    assert(!bst.contains(10));
    assert(!bst.insert(3));

    assert((bst.inorder() == vector<int>{2, 3, 4, 5, 6, 7, 8}));

    // Test 4: Leaf Node 삭제
    assert(bst.erase(2));
    assert(!bst.contains(2));

    // Test 5: 자식이 하나인 Node 삭제
    assert(bst.erase(3));
    assert(!bst.contains(3));
    assert(bst.contains(4));

    // Test 6: 자식이 둘인 Node 삭제
    assert(bst.erase(7));
    assert(!bst.contains(7));

    // Test 7: Root 삭제
    assert(bst.erase(5));
    assert(!bst.contains(5));

    assert((bst.inorder() == vector<int>{4, 6, 8}));

    // Test 8: 존재하지 않는 값 삭제
    assert(!bst.erase(100));

    cout << "All tests passed!\n";
    return 0;
}