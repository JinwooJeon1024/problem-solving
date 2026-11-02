  #include<vector>
  #include<unordered_set>

  using namespace std;

  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;  
    
    for(auto num: nums) {
      s.insert(num);
    }

    int mx = 1;

    for(auto num: s) {
      if(s.count(num-1)) continue;
      else {
        int cur = num+1;
        while(s.count(cur)) {
          mx = max(mx, cur - num + 1);
          cur++;
        }
      }
    }

    return mx;
  }