#include<bits/stdc++.h>

using namespace std;

int n, k, a, b;
multiset<pair<int, int>> m;
multiset<int> c;

int main(void) {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    m.insert({a, b});
  }
  for(int i = 0; i < k; i++) {
    cin >> a;
    c.insert(a);
  }
}