#include <bits/stdc++.h>
using namespace std;

class MyMinHeap {
private:
    int size_;
    int capacity_;
    int* data;

public:
    MyMinHeap(int capacity):
      size_(0), capacity_(capacity), data(new int[capacity+1]) {}

    bool push(int value) {
      if(size_ == capacity_) return false;

      data[++size_] = value;

      int cur = size_;
      int parent = cur / 2;

      while(parent > 0 && data[cur] < data[parent]) {
        swap(data[cur], data[parent]);
        cur = parent;
        parent = cur / 2;
      }

      return true;
    }
    bool pop() {
      if(size_ == 0) return false;

      swap(data[1], data[size_--]);

      int cur = 1;
      int n = size_;

      while(cur*2 <= n) {
        int child = cur*2;
        if(child+1 <= n && data[child] > data[child+1]) child++;

        if(data[child] >= data[cur]) break;

        swap(data[cur], data[child]);
        cur = child;
      }

      return true;
    }

    int top() const {
      if(size_ == 0) return -1;

      return data[1];
    }

    bool empty() const {
      return size_ == 0;
    }
    int size() const {
      return size_;
    }
};

int main() {
    MyMinHeap h(5);

    // Test 1: 빈 Heap
    assert(h.empty());
    assert(h.size() == 0);
    assert(h.top() == -1);
    assert(!h.pop());

    // Test 2: 삽입
    assert(h.push(5));
    assert(h.push(2));
    assert(h.push(8));
    assert(h.push(1));
    assert(h.push(3));

    assert(h.size() == 5);
    assert(h.top() == 1);
    assert(!h.push(10));  // Full

    // Test 3: 정렬된 순서로 제거
    vector<int> result;

    while (!h.empty()) {
        result.push_back(h.top());
        h.pop();
    }

    assert((result == vector<int>{1, 2, 3, 5, 8}));

    // Test 4: 중복 및 음수
    assert(h.push(-4));
    assert(h.push(0));
    assert(h.push(-4));

    assert(h.top() == -4);
    assert(h.size() == 3);

    assert(h.pop());
    assert(h.top() == -4);

    cout << "All tests passed!\n";

    return 0;
}