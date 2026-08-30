#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

#define X first
#define Y second

using namespace std;

int arr[20][20], vis[20][20];

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

queue<pair<int, int>> q;

void bfs(int i, int j) {
    q.push({i, j});

    while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = c.X + dirX[k];
            int ny = c.Y + dirY[k];

            // 무조건 범위부터
            if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16)
                continue;

            if (vis[nx][ny])
                continue;

            if (arr[nx][ny] == 1)
                continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int solve() {
    vis[1][1] = 1;
    bfs(1, 1);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (arr[i][j] == 3 && vis[i][j])
                return 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 0; t < 10; t++) {
        int tc;
        cin >> tc;

        for (int i = 0; i < 16; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 16; j++) {
                arr[i][j] = s[j] - '0';
            }
        }

        for (int i = 0; i < 16; i++) {
            fill(vis[i], vis[i] + 16, 0);
        }

        cout << "#" << tc << " " << solve() << '\n';
    }
}