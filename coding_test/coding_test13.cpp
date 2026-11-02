#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
  if(root == nullptr) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }

  if(root->value > value) {
    root->left = insert(root->left, value);
    return root;
  }
  else if(root->value < value) {
    root->right = insert(root->right, value);
    return root;
  }
  
  return root;
}

bool search(Node* root, int value) {
  if(root == nullptr) return false;

  if(root->value == value) return true;
  else if(root->value < value) {
    return search(root->right, value);
  }
  else if(root->value > value) {
    return search(root->left, value);
  }

}

Node* remove(Node* root, int value) {
  if(root == nullptr) {
    return nullptr;
  }

  if(root->value == value) {
    if(root->right == nullptr && root->left == nullptr) {
      delete root;
      return nullptr;
    }
    else if(root->right && root->left) {
      Node* successor = root->right;

      while (successor->left != nullptr) {
        successor = successor->left;
      }

      root->value = successor->value;
      root->right = remove(root->right, successor->value);

      return root;
    }
    else if(root->right) {
      Node* rc = root->right;
      delete root;
      return rc;
    }
    else if(root->left) {
      Node* lc = root->left;
      delete root;
      return lc;
    }
  }
  else if(root->value < value) {
    root->right = remove(root->right, value);
    return root;
  }
  else if(root->value > value) {
    root->left = remove(root->left, value);
    return root;
  }

}