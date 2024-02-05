#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k, l, x, a, b, t, idx;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> tails = {{0, 0}};
vector<pair<int, int>>::iterator it = dir.begin();

int board[102][102]; // 0: 빈 칸, 1: 뱀, 2: 사과
char c;

map<int, char> m;
pair<int, int> head = {0, 0}; 
pair<int, int> tail = {0, 0};

bool isEnd(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] == 1) return true;
    else return false;
}

// return 0: 게임 종료
int solve(int t){ 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++) cout << board[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // 뱀 이동
    int r = head.X + (*it).X;
    int c = head.Y + (*it).Y;

    // cout << "r: " << r << " c: " << c << '\n';
    // cout << tail.X << ' ' << tail.Y << '\n';
    // for(auto c: tails) cout << c.X << ' ' << c.Y << '\n';
    if(isEnd(r,c)){
        cout << t;
        return 0;
    }

    tails.push_back({r, c});
    head.X = r;
    head.Y = c;

    if(board[r][c] == 0){
        board[tail.X][tail.Y] = 0;
        tail = tails[++idx];
    }

    board[r][c] = 1;
    return 1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    while(k--){
        cin >> a >> b;
        board[a-1][b-1] = 2;
    }
    board[0][0] = 1;

    cin >> l;
    while(l--){
        cin >> x >> c;
        m[x] = c;
    }

    
    while(solve(++t)){
        if(m.count(t)){
            if(m[t] == 'L'){
                if(it == dir.begin()) it = dir.end();
                it--;
            }
            else if(m[t] == 'D'){
                if(it == --dir.end()) it = dir.begin() - 1;
                it++;
            }
        }
    }  

    return 0;
}