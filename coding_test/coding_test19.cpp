#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int>& v, int target, int start, int end) {
  if(start == end) {
    if(target == v[start]) return start;
    else return -1;
  }

  if(v[start] < v[end]) { // sorted case
    auto it = lower_bound(v.begin()+start, v.begin()+end+1, target);

    if(it == v.begin()+end+1 || *it != target) return -1;

    return it - v.begin();
  }

  else { // unsorted case
    int mid = start + (end - start) / 2;

    if(v[start] < v[mid]) {
      if(v[start] <= target && target <= v[mid]) return bsearch(v, target, start, mid);
      else if(v[mid+1] <= target || target >= v[end]) return bsearch(v, target, mid+1, end);
      else return -1;
    }
    else if(v[mid+1] < v[end]) {
      if(v[mid+1] <= target && target <= v[end]) return bsearch(v, target, mid+1, end);
      else if(v[start] <= target || target >= v[mid]) return bsearch(v, target, start, mid);
      else return -1;
    }
  }

}

int search(vector<int>& nums, int target) {
  int n = nums.size();

  return bsearch(nums, target, 0, n-1);  
}