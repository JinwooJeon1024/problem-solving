#include<bits/stdc++.h>
using namespace std;

int dis[202][202];
bool vis[202][202];
int dis2[202][202];
bool vis2[202][202];

int w, h, k;
int board[202][202];

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, -1, 1, 2, -2, 1, -1};

int dx2[4] = {1, -1, 0, 0};
int dy2[4] = {0, 0, 1, -1};

void bfs(int r, int c) {
  queue<pair<int, int>> q;

  q.push({r, c});
  vis[r][c] = 1;

  int horse = k;

  while(!q.empty() && horse--) {
    pair<int, int> cur = q.front();
    q.pop();

    for(int i = 0; i < 8; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(vis[nx][ny]) continue;
      if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if(board[nx][ny] == 1) continue;

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

void bfs2(int r, int c) {
  queue<pair<int, int>> q;

  q.push({r, c});
  vis2[r][c] = 1;

  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = cur.first + dx2[i];
      int ny = cur.second + dy2[i];

      if(vis2[nx][ny]) continue;
      if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if(board[nx][ny] == 1) continue;

      dis2[nx][ny] = dis2[cur.first][cur.second] + 1;
      vis2[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int ans() {
  int ret = INT_MAX;
  bool find = 0;

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(dis[i][j] >= 0 && dis2[i][j] >= 0){
        ret = min(ret, dis[i][j] + dis2[i][j]);
        find = 1;
      } 
    }
  }
  
  if(find) return ret;
  else return -1;
}

void solve() {
  bfs(0, 0);
  bfs2(h-1, w-1);

  cout << ans();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k >> w >> h;

  memset(dis, -1, sizeof(dis));
  dis[0][0] = 0;
  memset(dis2, -1, sizeof(dis2));
  dis2[h-1][w-1] = 0;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++) {
      cin >> board[i][j];
    }

  
  solve();

  // cout << '\n';
  // for(int i = 0; i < h; i++) {
  //   for(int j = 0; j < w; j++) {
  //     cout << dis[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // cout << '\n';
  // for(int i = 0; i < h; i++) {
  //   for(int j = 0; j < w; j++) {
  //     cout << dis2[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}