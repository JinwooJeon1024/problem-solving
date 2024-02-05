#include<bits/stdc++.h>
using namespace std;

int n, m, k, a, b;
int parent[1000002];

int Find(int x) {
	if (x == parent[x]) return x;

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

void solve(int k, int a, int b){
    if(k == 0){
        Union(a, b);        
    } else {
        if(a == b || Find(a) == Find(b)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;

    while(m--){
        cin >> k >> a >> b;
        solve(k, a, b);
    }
    return 0;
}