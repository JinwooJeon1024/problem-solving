#include<vector>
#include<algorithm>
#include<queue>
#define X first
#define Y second

using namespace std;
int dist[1005][1005];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0 ,-1, 0};

int shortestPath(const vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<int, int>> q;

  for(int i = 0; i < 1000; i++) fill(dist[i], dist[i]+1000, -1);

  dist[0][0] = 0;
  q.push({0, 0});

  while(!q.empty()) {
    auto c = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = c.X + dx[dir], ny = c.Y + dy[dir];

      if(nx < 0 || nx >= n ||  ny < 0 ||  ny >= m) continue;
      if(grid[nx][ny] == 1 || dist[nx][ny] >= 0) continue;

      dist[nx][ny] = dist[c.X][c.Y] + 1;
      q.push({nx, ny});
    }
  }

  if(grid[0][0] == 1) dist[0][0] = -1;

  return dist[n-1][m-1];
}
