#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
      if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);

      return get<2>(a) < get<2>(b);
    }
};

class JobScheduler {
private:
    int time;
    set<tuple<int, int, int>, cmp> s;
    unordered_map<int, pair<int, int>> mp;
public:
    JobScheduler():
      time(0) {}

    void addJob(int jobId, int priority) {
      mp[jobId] = {priority, time};
      s.insert({jobId, priority, time});
      time++;
    }
    bool cancelJob(int jobId) {
      if(mp.find(jobId) == mp.end()) return false;
      s.erase({jobId, mp[jobId].first, mp[jobId].second});
      mp.erase(jobId);

      return true;
    }

    int runNext() {
      if(s.size() == 0) return -1;
      
      auto tmp = *s.begin();
      s.erase(tmp);
      mp.erase(get<0>(tmp));

      return get<0>(tmp);
    }
    int pendingCount() {
      return s.size();
    }
};

int main() {
  JobScheduler s;
  s.addJob(10, 2);
  s.addJob(20, 5);
  s.addJob(30, 5);

  cout << s.pendingCount() << '\n'; // 3

  cout << s.runNext() << '\n';       // 20
  cout << s.cancelJob(20) << '\n';   // 0

  cout << s.cancelJob(30) << '\n';   // 1
  cout << s.cancelJob(30) << '\n';   // 0

  cout << s.pendingCount() << '\n'; // 1
  cout << s.runNext() << '\n';       // 10
  cout << s.runNext() << '\n';       // -1
}