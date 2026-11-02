#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll m, k;
vector<ll> v;

int main(void) {
  cin >> n >> m;
  while(n--) {
    cin >> k;
    v.push_back(k);
  }

  sort(v.begin(), v.end());

  int l = 0;
  int r = n-1;

  while(v[r] - v[l] >= m) {
    l++;
  }
  l--;

  while(v[r] - v[l] >= m) {
    r--;
  }
  r++;

  cout << v[r] - v[l];
}