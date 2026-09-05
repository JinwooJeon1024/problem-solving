#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int b[105], t[105];
int tc, n, m, k;

void solve() {
  b[0] = 0;
  t[0] = 0;
  sort(t+1, t+n+1);
 
  for(int i = 1; i <= n; i++) {
    b[i] = b[i-1] + ((t[i]/m)-(t[i-1]/m))*k - 1;
    if(b[i] < 0) {
      cout << "Impossible";
      return;
    }
  }

  cout << "Possible";
  return;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  for(int i = 1 ; i <= tc; i++) {
    cin >> n >> m >> k;
   
    for(int j = 1; j <= n; j++) {
      cin >> t[j];
    }

    


    cout << "#" << i << " ";
    solve();
    cout << "\n";
  }
}