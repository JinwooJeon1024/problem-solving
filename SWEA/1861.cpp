#include<iostream>
#include<algorithm>
#include<queue>

#define X first
#define Y second

using namespace std;

int arr[1005][1005], vis[1005][1005], ans[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, tc, mx, num;
queue<pair<int, int>> q;

int fun(int i, int j) {
  vis[i][j] = 1;

  for(int dir = 0; dir < 4; dir++){
    int nx = i + dx[dir];
    int ny = j + dy[dir];

    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

    if(arr[nx][ny] == arr[i][j]+1) {

      return ans[i][j] = fun(nx, ny)+1;
    }
  }

  ans[i][j] = 1;
  return 1;
}

void solve() {

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j]) continue;

      ans[i][j] = fun(i, j);
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(mx < ans[i][j] || (mx == ans[i][j] && num > arr[i][j])){
        num = arr[i][j];
        mx = ans[i][j];
      } 
    }
  }

  cout << num << " " << mx;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cin >> n;
    for(int j = 0; j < n ; j++) {
      for(int k = 0; k < n; k++) {
        cin >> arr[j][k];
      }
    }

    cout << "#" << i << " ";
    solve();
    cout << '\n';

    for(int m = 0; m < 1005; m++) {
      fill(arr[m], arr[m]+1005, 0);
      fill(vis[m], vis[m]+1005, 0);
      fill(ans[m], ans[m]+1005, 0);
    }
    mx = num = 0;
  }
  
}

