#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
  vector<int> prefix;
  int sum = 0;
  for(auto num: nums) {
    sum += num;
    prefix.push_back(sum);
  }

  unordered_map<int, int> mp;
  int index = 0;
  for(auto num: prefix) {
    mp[num] = index++;
  }

  index = 0;
  int ans = 0;
  for(auto num: prefix) {
    ans = max(ans, mp.count(num+k) ? mp[num+k]-index : 0);
    index++;
  }

  return ans;
}