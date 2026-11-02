class MyCircularQueue {
private:
    int* data;
    int head;
    int tail;
    int size_;
    int capacity_;

public:
    MyCircularQueue(int capacity) :
      head(0), tail(-1), size_(0), capacity_(capacity) {
        data = new int[capacity];
      }

    bool push(int value) {
      if(size_ == capacity_) return false;

      tail++;
      if(tail == capacity_) 
        tail = 0;

      data[tail] = value;
      size_++;

      return true;
    }

    bool pop() {
      if(size_ == 0) return false;

      head++;
      if(head == capacity_)
        head = 0;
      
      size_--;
      return true;
    }

    int front() const {
      if(size_ == 0) return -1;

      return data[head];
    }

    bool empty() const {
      return size_ == 0;
    }

    bool full() const {
      return size_ == capacity_;
    }

    int size() const {
      return size_;
    }
};