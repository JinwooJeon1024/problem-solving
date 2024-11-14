#include<bits/stdc++.h>
using namespace std;

int dis[202][202];
bool vis[202][202];

int w, h, k;
int board[202][202];

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, -1, 1, 2, -2, 1, -1};

int dx2[4] = {1, -1, 0, 0};
int dy2[4] = {0, 0, 1, -1};

void bfs(int r, int c) {
  queue<tuple<int, int, int>> q;

  q.push(make_tuple(r, c, k));
  vis[r][c] = 1;

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();

    for(int dir = 0; dir < 8; dir++) {
      int nx = get<0>(cur) + dx[dir];
      int ny = get<1>(cur) + dy[dir];
      int nk = get<2>(cur) - 1;

      if(vis[nx][ny]) continue;
      if(nx < 0 || nx >= w || ny < 0 || ny >= h || nk < 0) continue;
      if(board[nx][ny] == 1) continue;

      dis[nx][ny] = dis[get<0>(cur)][get<1>(cur)] + 1;
      vis[nx][ny] = 1;
      q.push(make_tuple(nx, ny, nk));
    }
    
    for(int dir = 0; dir < 4; dir++) {
      int nx = get<0>(cur) + dx2[dir];
      int ny = get<1>(cur) + dy2[dir];
      int nk = get<2>(cur);

      if(vis[nx][ny]) continue;
      if(nx < 0 || nx >= w || ny < 0 || ny >= h || nk < 0) continue;
      if(board[nx][ny] == 1) continue;

      dis[nx][ny] = dis[get<0>(cur)][get<1>(cur)] + 1;
      vis[nx][ny] = 1;
      q.push(make_tuple(nx, ny, nk));
    }
  }
}

void solve() {
  bfs(0, 0);

  cout << dis[h-1][w-1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k >> w >> h;

  memset(dis, -1, sizeof(dis));
  dis[0][0] = 0;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++) {
      cin >> board[i][j];
    }
  
  solve();

  cout << '\n';
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cout << dis[i][j] << ' ';
    }
    cout << '\n';
  }
}