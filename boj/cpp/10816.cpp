#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[500002];

int solve(int t){
  int idx1, idx2;
  int st = 0, en = n-1;

  while(st <= en) {
    int mid = (st+en)/2;

    if(arr[mid] < t) st = mid+1;
    else if(arr[mid] > t) en = mid-1;
    else {
      idx1 = mid, idx2 = mid;
      while(idx1 > 0, arr[idx1-1] == t) {
        idx1--;
      }

      while(idx2 < n-1, arr[idx2+1] == t) {
        idx2++;
      }

      return idx2-idx1+1;
    }
  }

  return 0;
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
    cout << upper_bound(arr, arr+n, t) - lower_bound(arr, arr+n, t) << ' ';
  }
}