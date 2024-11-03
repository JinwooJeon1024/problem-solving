#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[500002];

int solve(int t){
  int ret = 0;
  int st = 0, en = n-1;

  while(st <= en) {
    int mid = (st+en)/2;

    if(arr[mid] < t) st = mid+1;
    else if(arr[mid] > t) en = mid-1;
    else {
      while(mid > st && arr[mid] == t) if(arr[mid-1] == t) mid--;
      while(mid <= en && arr[mid++] == t) ret++;

      return ret;
    }
  }

  return ret;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  cin >> m;

  sort(arr, arr+n);

  while(m--) {
    cin >> t;
    cout << solve(t) << ' ';
  }
}