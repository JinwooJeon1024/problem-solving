#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int mx = 100;
int n;
int board[mx+5][mx+5];
int color_board[mx+5][mx+5];
int dis[mx+5][mx+5];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int r, int c, int color) { // O(n^2)
  bool vis[mx+5][mx+5] = {0, };
  queue<pair<int, int>> q;

  q.push({r, c});

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    color_board[cur.X][cur.Y] = color;

    for(int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(vis[nx][ny]) 
        continue;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) 
        continue;
      if(board[nx][ny] == 0) 
        continue;

      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int min_bfs(int r, int c, int color) { // r, c칸의 다른 색 섬까지의 최소 거리
  bool vis[mx+5][mx+5] = {0, };
  int dis[mx+5][mx+5];
  queue<pair<int, int>> q;

  memset(dis, -1, sizeof(dis));

  dis[r][c] = 0;
  q.push({r, c});

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(vis[nx][ny]) 
        continue;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) 
        continue;

      if(color_board[nx][ny] == color)
        continue;
      else if(color_board[nx][ny] != 0) {
        return dis[cur.X][cur.Y] + 1;
      }
      
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  return INT_MAX;
}

void solve() {
  int color = 1;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(color_board[i][j] != 0) 
        continue;
      
      if(board[i][j] == 0)
        continue;

      bfs(i, j, ++color);
    }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dis[i][j] = min_bfs(i, j, color_board[i][j]);

  int ans = INT_MAX;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      ans = (ans > dis[i][j]) && (board[i][j] != 0) ? dis[i][j] : ans;

  // cout << '\n';
  // cout << "---------dis-----------\n";

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cout << dis[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // cout << '\n';
  // cout << "---------color_board-----------\n";

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cout << color_board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  
  cout << ans-1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];
  
  solve();
}
