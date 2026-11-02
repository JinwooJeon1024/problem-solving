#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    int size;
    vector<int> v1, v2;

public:
    MinStack():
      size(0) {}

    void push(int value) {
      v1.push_back(value);
      size++;
    }

    bool pop() {
      if(size == 0) return false;

      v1.pop_back();
      size--;
      return true;
    }

    int top() {
      if(size == 0) return -1;

      return v1[size-1];
    }
    int getMin() {
      return v2.front();
    }

    bool empty() {
      return size == 0;
    }
};