#include<bits/stdc++.h>
using namespace std;

class RecentChats {
private:
    int time;
    list<int> l;
    unordered_map<int, list<int>::iterator> ump;

public:
    RecentChats():
      time(0) {}

    void touch(int chatId) {
      unordered_map<int, list<int>::iterator>::iterator it = ump.find(chatId);
      if(it == ump.end()) {
        l.push_front(chatId);
        ump[chatId] = l.begin();
      }
      else {
        l.erase(it->second);
        l.push_front(chatId);
        ump[chatId] = l.begin();
      }
    }

    vector<int> recent(int k) {
      vector<int> ret;

      for(auto cur: l) {
        if(ret.size() == k) return ret;
        ret.push_back(cur);
      }

      return ret;
    }
};