#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[6], n, m, t;
vector <int> v;

void dfs(int depth) {
  if (depth == n) {
    for (int i = 0; i < m; i++) {
      t += arr[i];
      t *= 10;
    }
    v.push_back(t);
    return;
  }

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      swap(arr[i], arr[j]);
      dfs(depth+1);
      swap(arr[i], arr[j]);
    }
  }
}

int solve(){

  dfs(0);

  return *max_element(v.begin(), v.end());
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  string s;

  cin >> tc;

  for(int k = 1; k <= tc; k++){
    cin >> s >> n;
    m = s.length();

    for(int i = 0; i < m; i++) arr[i] = s[i];
    cout << "#" << k << " " << solve() << "\n";
  }
}