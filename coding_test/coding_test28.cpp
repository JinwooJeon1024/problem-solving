#include<bits/stdc++.h>
using namespace std;

const int MX = 1007;

class MyHashMap {
private:
    int size_;
    vector<vector<int>> v;
    int hash(int n) {
      std::hash<int> hasher;
      
      return hasher(n) % MX;
    }
public:
    MyHashMap():
      size_(0), v(MX) {}

    void put(int key, int value);
    bool get(int key, int& value) {
      int n = hash(key);
      for(const auto& cur: v[n]) {
        if(value == cur) {
          return true;
        }
      }

      return false;
    }
    bool remove(int key);

    int size() const {
      return size_;
    }
};