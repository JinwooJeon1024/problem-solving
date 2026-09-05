#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int vis[10], n, m, t;
string s;
vector <int> v;

void dfs(int depth) {
  if (depth == n) {
    t = s[0] - '0';
    for (int i = 1; i < m; i++) {
      t *= 10;
      t += s[i] - '0';
    }
    return;
  }

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      swap(s[i], s[j]);
      vis[]
      if(vis[])
      dfs(depth+1);
      swap(s[i], s[j]);
    }
    
  }
}

int solve(){

  dfs(0);

  return t;
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;

  cin >> tc;

  for(int k = 1; k <= tc; k++){
    cin >> s >> n;
    m = s.length();

    cout << "#" << k << " " << solve() << "\n";
  }
}