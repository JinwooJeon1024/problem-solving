#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minMeetingRooms(vector<pair<int, int>>& meetings) {
  vector<pair<int, int>> v;
  int current = 0, ans = 0;

  for(auto m: meetings) {
   v.push_back({m.first, 1}); 
   v.push_back({m.second, -1}); 
  }

  sort(v.begin(), v.end());

  for(auto m2: v) {
    current += m2.second;
    ans = max(current, ans);
  }

  return ans;
}

