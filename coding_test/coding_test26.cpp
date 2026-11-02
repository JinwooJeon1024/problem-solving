#include<bits/stdc++.h>
using namespace std;

vector<int> nextWarmerDay(vector<int>& temperatures) {
  stack<pair<int, int>> s;
  vector<int> ret;
  int n = temperatures.size();

  for(int i = n-1; i >= 0; i++) {
    int cur = temperatures[i];

    while(!s.empty() && s.top().first <= cur) {
      s.pop();
    }

    if(s.empty()) {
      ret.push_back(0);
      s.push({cur, i});
      continue;
    }

    ret.push_back(s.top().second - i);
    s.push({cur, i});
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

class TemperatureTracker {
private:
    int time;
    stack<pair<int, int>> s;
public:
    TemperatureTracker():
      time(0) {}

    vector<pair<int, int>> addTemperature(int temp) {
      vector<pair<int, int>> ret;
      while(!s.empty() && s.top().second < temp) {
        ret.push_back({s.top().first, time - s.top().first});
        s.pop();
      }

      s.push({time++, temp});
      return ret;
    }
};