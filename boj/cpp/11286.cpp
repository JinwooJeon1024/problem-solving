#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(int a, int b) const {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }

        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n--) {
        cin >> x;

        if (x != 0) {
            pq.push(x);
        }
        else {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}