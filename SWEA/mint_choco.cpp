#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n, t;
int f[55][55], b[55][55], vis[55][55], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
string s;
queue<pair<int, int>> q;
struct King {
	int i;
	int j;
	int b;
};
vector<King> v;
vector<pair<int, int>> guard;
vector<int> ans(7);

bool OOB(int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= n;
}

void print() {
	cout << "-----------------------------\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << f[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-----------------------------\n";
}


bool cmp(King& p, King& q) {
	if(p.b != q.b) {
		return p.b > q.b;
	}
	else if(p.i != q.i) {
		return p.i < q.i;
	}
	else {
		return p.j < q.j;
	}
}

set<int> intoSet(int f) {
	switch(f) {
		case 1:
			return {1};
		case 2:
			return {2};
		case 3:
			return {3};
		case 4:
			return {2, 3};
		case 5:
			return {1, 3};
		case 6:
			return {1, 2};
		case 7:
			return {1, 2, 3};
	}
}

int intoFood(set<int>& s) {
	if(s.size() == 3) {
		return 7;
	}
	else if(s.size() == 1) {
		return *s.begin();
	}
	else {
		if(!s.count(1)) {
			return 4;
		}
		else if(!s.count(2)) {
			return 5;
		}
		else if(!s.count(3)) {
			return 6;
		}
	}
}

void morning() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			b[i][j] += 1;
		}
	}
}

void launch() {
	for(int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, 0);
	}
	v.clear();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(vis[i][j]) continue;

			int food = f[i][j];
			int bMax = b[i][j];
			vector<King> group;
			group.push_back({i, j, b[i][j]});

			q.push({i, j});
			vis[i][j] = 1;

			while(!q.empty()) {
				auto cur = q.front(); q.pop();

				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if(OOB(nx, ny) || vis[nx][ny] || f[nx][ny] != food) continue;

					vis[nx][ny] = 1;
					q.push({nx, ny});
					group.push_back({nx, ny, b[nx][ny]});
				}
			}
	
			sort(group.begin(), group.end(), cmp);
			// for(auto c: group) {
			// 	cout << c.b << ' ';
			// }
			
			auto& curKing = group[0];
			for(auto& cur: group) {
				b[cur.i][cur.j]--;
				b[curKing.i][curKing.j]++;
				cur.b--;
				curKing.b++;
			}

			v.push_back(curKing);
		}
	}
}

void transfer(King& curKing) {
		int dir = curKing.b % 4;
		int x = curKing.b - 1;
		b[curKing.i][curKing.j] = 1;
		int food = f[curKing.i][curKing.j];
		int nx = curKing.i + dx[dir];
		int ny = curKing.j + dy[dir];

		while(!OOB(nx, ny) && x > 0) {
			if(f[nx][ny] != food) {
				int y = b[nx][ny];

				if(x > y) {
					f[nx][ny] = food;
					x -= (y + 1);
					b[nx][ny] += 1;
					guard.push_back({nx, ny});
				}
				else if(x <= y) {
					b[nx][ny] += x;
					x = 0;
					set<int> newS;
					for(auto cur: intoSet(f[nx][ny])) {
						newS.insert(cur);
					}

					for(auto cur: intoSet(food)) {
						newS.insert(cur);
					}
					f[nx][ny] = intoFood(newS);
					guard.push_back({nx, ny});
				}
			}

			nx = nx + dx[dir];
			ny = ny + dy[dir];
			// cout << "after transfer\n";
			// print();
		}
}

void dinner() {
	sort(v.begin(), v.end(), cmp);
	// for(auto c: v) {
	// 	cout << c.b << ' ';
	// }
	// cout << '\n';
	guard.clear();

	for(auto& curKing: v) {
		int curFood = f[curKing.i][curKing.j];
		bool guardBool = false;
		if(curFood != 1 && curFood != 2 && curFood != 3) continue;
		for(auto g: guard) {
			if(g.first == curKing.i && g.second == curKing.j) {
				guardBool = true;
			}
		}
		if(guardBool) continue;
		transfer(curKing);
	}

	for(auto& curKing: v) {
		int curFood = f[curKing.i][curKing.j];
		bool guardBool = false;
		if(curFood != 4 && curFood != 5 && curFood != 6) continue;
		for(auto g: guard) {
			if(g.first == curKing.i && g.second == curKing.j) {
				guardBool = true;
			}
		}
		if(guardBool) continue;
		transfer(curKing);
	}

	for(auto& curKing: v) {
		int curFood = f[curKing.i][curKing.j];
		bool guardBool = false;
		if(curFood != 7) continue;
		for(auto g: guard) {
			if(g.first == curKing.i && g.second == curKing.j) {
				guardBool = true;
			}
		}
		if(guardBool) continue;
		transfer(curKing);
	}
}


void solve() {
	morning();
	//print();
	launch();
	//print();
	dinner();
	//print();

	for(auto& c: ans) {
		c = 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans[f[i][j]-1] += b[i][j];
		}
	}

	reverse(ans.begin(), ans.end());

	for(auto c: ans) {
		cout << c << ' ';
	}
	cout << '\n';
}



int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> t;
	cin.ignore();

	for(int i = 0; i < n; i++) {
		getline(cin, s);

		for(int j = 0; j < n; j++) {
			if(s[j] == 'T') {
				f[i][j] = 1;
			}
			else if(s[j] == 'C') {
				f[i][j] = 2;
			}
			else if(s[j] == 'M') {
				f[i][j] = 3;
			}
		}
	}

	for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
	}

	for(int i = 1 ; i <= t; i++) {
		solve();
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}