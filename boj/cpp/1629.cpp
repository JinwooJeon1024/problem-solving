#include<bits/stdc++.h>
using namespace std;
long long a, b, c;

long long solve(long long x, long long y, long long z){ // x를 y번 곱한 수를 z로 나눈 나머지
  if(y == 1) return x % z;

  if(y % 2)
    return (solve(x, y / 2, z) * solve(x, (y / 2) + 1, z)) % z;
  else
    return (solve(x, y / 2, z) * solve(x, y / 2, z)) % z;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> c;
  cout << solve(a, b, c);

  return 0;
}