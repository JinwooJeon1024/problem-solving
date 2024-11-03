#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int t){
  int st = 0;
  int en = v.size() - 1;

  while(st <= en) {
    int mid = (st + en) / 2;

    if(v[mid] < t) st = mid + 1;
    else if(v[mid] > t) en = mid - 1;
    else return 1;
  }

  return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> t;
    // cout << binary_search(v.begin(), v.end(), t) << '\n';
    cout << solve(v, t) << '\n';
  }

  return 0;
}