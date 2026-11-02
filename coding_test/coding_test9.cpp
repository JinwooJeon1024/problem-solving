#include<algorithm>
using namespace std;

class MyMinHeap {
private:
    int* data;
    int capacity_;
    int size_;

public:
    MyMinHeap(int capacity):
      capacity_(capacity), size_(0) {
        data = new int[capacity+1];
      }
    
    ~MyMinHeap() {
      delete[] data;
    }

    bool push(int value) {
      if(size_ == capacity_) return false;

      data[++size_] = value;

      int cur = size_;
      int parent = cur / 2;

      while(parent > 0) {
        if(data[parent] > data[cur]) {
          swap(data[parent], data[cur]);
          cur = parent;
          parent = cur / 2;
        }
        else {
          break;
        }
      }

      return true;
    }

    bool pop() {
      if(size_ == 0) return false;

      swap(data[1], data[size_]);
      size_--;

      int cur = 1;
      int lc = cur*2, rc = cur*2+1;
      while(cur <= size_) {
        if(lc > size_) break;
        else if(rc > size_) {
          if(data[cur] <= data[lc]) break;
          else {
            swap(data[cur], data[lc]);
            break;
          }
        }
        else {
          int minChild = data[lc] < data[rc] ? lc : rc;

          if(data[cur] <= data[minChild]) break;
          swap(data[cur], data[minChild]);
          cur = minChild;
          lc = cur*2;
          rc = cur*2+1;
        }
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