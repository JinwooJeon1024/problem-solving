#include<bits/stdc++.h>
using namespace std;

int n, x, y, s, e, ret;
vector<pair<int, int>> v;

int solve() {
  int s = (*v.begin()).first;
  int e = (*v.begin()).second;

  for(auto c: v) {
    if(c.first <= e) {
      e = c.second > e ? c.second : e;
    }
    else {
      ret += e-s;
      s = c.first;
      e = c.second;
    }
  }

  return ret+(e-s);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  while(n--) {
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end());
  cout << solve();
}