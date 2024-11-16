#include<bits/stdc++.h>
using namespace std;

int n, m, s, e, t;
int arr[2005];
int dp[2005][2005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for(int i = 1; i <= n; i++) {
    dp[i][i] = 1;
    dp[i][i+1] = arr[i] == arr[i+1] ? 1 : 0;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++){ // i+j, i-j
      if(i-j <= 0 || i+j > n) 
        continue;

      dp[i-j][i+j] = arr[i-j] == arr[i+j] ? dp[i-j+1][i+j-1] : 0;
      dp[i-j][i+j+1] = arr[i-j] == arr[i+j+1] ? dp[i-j+1][i+j] : 0;
    }
  }

  cin >> m;
  while(m--){
    cin >> s >> e;
    cout << dp[s][e] << '\n';
  }
}
