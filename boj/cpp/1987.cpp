#include<bits/stdc++.h>
using namespace std;

int r, c, ans, temp;
char board[22][22];
bool alpha[26];
string s;

bool isDone(int x, int y){
    return x < 0 || x >= r || y < 0 || y >= c || alpha[board[x][y] - 'A'];
}

int solve(int x, int y, int n){ // board[x][y]에 n개를 가지고 도착. 이 칸에서 갈 수 있는 4칸에 대해서 백트래킹 갈 수 있는 칸이 없다면 return n;
    if(!isDone(x+1, y)){
        alpha[board[x+1][y] - 'A'] = true;
        temp = solve(x+1, y, n+1);
        ans = ans < temp ? temp : ans;
        alpha[board[x+1][y] - 'A'] = false;
    }

    if(!isDone(x, y-1)){
        alpha[board[x][y-1] - 'A'] = true;
        temp = solve(x, y-1, n+1);
        ans = ans < temp ? temp : ans;
        alpha[board[x][y-1] - 'A'] = false;
    }

    if(!isDone(x-1, y)){
        alpha[board[x-1][y] - 'A'] = true;
        temp = solve(x-1, y, n+1);
        ans = ans < temp ? temp : ans;
        alpha[board[x-1][y] - 'A'] = false;
    }

    if(!isDone(x, y+1)){
        alpha[board[x][y+1] - 'A'] = true;
        temp = solve(x, y+1, n+1);
        ans = ans < temp ? temp : ans;
        alpha[board[x][y+1] - 'A'] = false;
    }

    if(isDone(x+1, y+1) && isDone(x+1, y-1) && isDone(x-1, y+1) || isDone(x-1, y-1)) return n;
    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++) board[i][j] = s[j];
    }
    
    alpha[board[0][0] - 'A'] = true;
    ans = 1;
    solve(0, 0, 1);

    // for(auto c: ans) cout << c << ' ';
    // cout << '\n';
    cout << ans;

    return 0;
}