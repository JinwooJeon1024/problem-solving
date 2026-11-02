#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> um;
  priority_queue<pair<int, int>, vector<pair<int, int>, greater<>>> pq;

  for(auto num: nums) {
    um[num]++;
  }

  for(auto& [key, value]: um) {
    if(pq.size() < k) {
      pq.push({value, key});
    }
    else {
      if(value > pq.top().first) {
        pq.pop();
        pq.push({value, key});
      }
    }
  }

  vector<int> ans;
  for(int i = 0; i < k; i++) {
    int a = pq.top().second;
    ans.push_back(a);
    pq.pop();
  }

  return ans;
}
