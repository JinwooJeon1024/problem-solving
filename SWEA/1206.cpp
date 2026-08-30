#include <bits/stdc++.h>
using namespace std;

int h[1005], m[1005];

int solve(int n) {
    int ret = 0;

    for (int i = 1; i < n; i++) {
        m[i] = max(h[i], h[i + 1]);
    }

    for (int i = 3; i <= n - 2; i++) {
        ret += max(0, h[i] - max(m[i - 2], m[i + 1]));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; tc++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }

        cout << "#" << tc << ' ' << solve(n) << '\n';
    }
}