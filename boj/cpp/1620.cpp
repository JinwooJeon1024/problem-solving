#include<bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<int, string> m1;
unordered_map<string, int> m2;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    cin >> s;
    m1[i] = s;
    m2[s] = i; 
  }

  while(m--) {
    cin >> s;
    if(isdigit(s[0])) {
      cout << m1[stoi(s)] << '\n';
    }
    else {
      cout << m2[s] << '\n';
    }
  }
}