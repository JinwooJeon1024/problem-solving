#include<iostream>
#include<unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int l = 0, r = 0, ans = 1, cnt = 1;

  unordered_set<char> us;
  us.insert(s[0]);

  for(int l = 0; l < s.length(); l++) {
    while(r < s.length() && l <= r) {
      r++;

      if(us.find(s[r]) != us.end()) {
        cnt--;
        us.erase(s[l]);
        break;
      }
      else {
        us.insert(s[r]);
        cnt++;
        ans = max(ans, cnt);
      }
    }

    if(r == s.length()) break;
  }

  return ans;
  
}

