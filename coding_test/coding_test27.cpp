#include<bits/stdc++.h>
using namespace std;

long long countValidRanges(vector<int>& events, int k) {
 unordered_map<int, int> cnt;
  long long ans = 0;
  int l = 0;

  for (int r = 0; r < (int)events.size(); r++) {

      // 현재 events[r]을 Window에 추가
      cnt[events[r]]++;

      while (cnt.size() > k) {

          // events[l]의 등장 횟수 감소
          cnt[events[l]]--;
          // 0이 되면 map에서 삭제
          if(cnt.count(events[l]) == 0) cnt.erase(events[l]);
          // l 증가
          l++;
      }

      // r에서 끝나는 유효한 부분배열의 수를 더하기
      ans += (r-l+1);
  }

  return ans;
}