#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<unordered_map>

using namespace std;

struct Request {
    int timestamp;
    string userId;
};

vector<bool> rateLimit(const vector<Request>& requests) {
  unordered_map<string, deque<int>> mp;
  vector<bool> ans;

  for(Request request: requests) {
    auto& q = mp[request.userId];

    if(q.empty() || q.size() < 3) {
      q.push_back(request.timestamp);
      ans.push_back(true);
    }
    else {
      if(request.timestamp < q.front()+10) {
        ans.push_back(false);
      }
      else {
        q.pop_front();
        q.push_back(request.timestamp);
        ans.push_back(true); 
      }
    }
  }

  return ans;
}