  #include <iostream>
  #include <algorithm>
  #define X first
  #define Y second

  using namespace std;

  int t, h, w, n, dir, flag;
  pair <int, int> p, q;
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  int board[25][25], new_board[25][25];
  string s[25], a;

  bool OOB(int i, int j) {
    return i < 0 || j < 0 || i >= h || j >= w;
  }

  void solve() {
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        switch (s[i][j]) {
          case '.': 
            board[i][j] = 1;
            break;
          case '*':
            board[i][j] = 2;
            break;
          case '#':
            board[i][j] = 3;
            break;
          case '-': 
            board[i][j] = 4;
            break;
          case '^':
            board[i][j] = 5;
            dir = 1;
            p = {i, j};
            break;
          case 'v': 
            board[i][j] = 6;
            dir = 2;
            p = {i, j};
            break;  
          case '<':
            board[i][j] = 7;
            dir = 3;
            p = {i, j};
            break;
          case '>':
            board[i][j] = 8;
            dir = 4;
            p = {i, j};
            break;
        }
      }
    }

    for(int i = 0; i < a.length(); i++){
      switch(a[i]) {
        case 'U':
          dir = 1;
          board[p.X][p.Y] = 5;
          if(!OOB(p.X-1, p.Y) && board[p.X-1][p.Y] == 1){
            board[p.X][p.Y] = 1;
            board[p.X-1][p.Y] = 5;
            p = {p.X-1, p.Y};
          }
          break;
        case 'D':
          dir = 2;
          board[p.X][p.Y] = 6;
          if(!OOB(p.X+1, p.Y) && board[p.X+1][p.Y] == 1){
            board[p.X][p.Y] = 1;
            board[p.X+1][p.Y] = 6;
            p = {p.X+1, p.Y};
          }
          break;
        case 'L':
          dir = 3;
          board[p.X][p.Y] = 7;
          if(!OOB(p.X, p.Y-1) && board[p.X][p.Y-1] == 1){
            board[p.X][p.Y] = 1;
            board[p.X][p.Y-1] = 7;
            p = {p.X, p.Y-1};
          }
          break;
        case 'R':
          dir = 4;
          board[p.X][p.Y] = 8;
          if(!OOB(p.X, p.Y+1) && board[p.X][p.Y+1] == 1){
            board[p.X][p.Y] = 1;
            board[p.X][p.Y+1] = 8;
            p = {p.X, p.Y+1};
          }
          break;
        case 'S':
          q = p;

          switch(dir) {
            case 1:
              flag = 1;
              while(!OOB(q.X, q.Y) && flag) {
                if(OOB(q.X-1, q.Y)) break;

                switch(board[q.X-1][q.Y]) {
                  case 1:
                  case 4:
                    q = {q.X-1, q.Y};
                    break;
                  case 2: 
                    board[q.X-1][q.Y] = 1;
                    flag = 0;
                    break;
                  case 3:
                    flag = 0;
                    break;
                }
              }
            break;
            case 2:
              flag = 1;
              while(!OOB(q.X, q.Y) && flag) {
                if(OOB(q.X+1, q.Y)) break;

                switch(board[q.X+1][q.Y]) {
                  case 1:
                  case 4:
                    q = {q.X+1, q.Y};
                    break;
                  case 2: 
                    board[q.X+1][q.Y] = 1;
                    flag = 0;
                    break;
                  case 3:
                    flag = 0;
                    break;
                }
              }
            break;
            case 3:
              flag = 1;
              while(!OOB(q.X, q.Y) && flag) {
                if(OOB(q.X, q.Y-1)) break;

                switch(board[q.X][q.Y-1]) {
                  case 1:
                  case 4:
                    q = {q.X, q.Y-1};
                    break;
                  case 2: 
                    board[q.X][q.Y-1] = 1;
                    flag = 0;
                    break;
                  case 3:
                    flag = 0;
                    break;
                }
              }
            break;
            case 4:
              flag = 1;
              while(!OOB(q.X, q.Y) && flag) {
                if(OOB(q.X, q.Y+1)) break;

                switch(board[q.X][q.Y+1]) {
                  case 1:
                  case 4:
                    q = {q.X, q.Y+1};
                    break;
                  case 2: 
                    board[q.X][q.Y+1] = 1;
                    flag = 0;
                    break;
                  case 3:
                    flag = 0;
                    break;
                  default:
                    break;
                }
              }
            break;
          }
      }
    }

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        switch(board[i][j]) {
          case 1: 
            cout << '.';
            break;
          case 2: 
            cout << '*';
            break;
          case 3: 
            cout << '#';
            break;
          case 4: 
            cout << '-';
            break;
          case 5: 
            cout << '^';
            break;
          case 6: 
            cout << 'v';
            break;
          case 7: 
            cout << '<';
            break;
          case 8: 
            cout << '>';
            break;
        }
      }

      cout << "\n";
    }
  }

  int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
      cin >> h >> w;
      for(int i = 0; i < h; i++){
        cin >> s[i];
      }
      cin >> n >> a;

      cout << "#" << tc << " ";
      solve();

    }
  }

