#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s;
string board[5];

bool isused[5][5];
int ans;

bool OOB(int r, int c, int x, int y) {
  return x < 0 || y < 0 || x >= 5 || y >= 5 || r > x || c > y;
}

int func(int r, int c, int t) {
  if(t == 1) {
    int snum = 0;

    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++) 
        if(isused[i][j]) snum++;
    
    return snum >= 4 ? 1 : 0;
  }

  isused[r][c] = 1;
  bfs(r, c, t);
  isused[r][c] = 0;
}

void solve() {
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      ans += func(i, j, 6);

  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++)
    cin >> board[i];

  solve();
}