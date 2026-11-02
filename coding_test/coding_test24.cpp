#include<bits/stdc++.h>
using namespace std;

long long minDeployTime(
    int n,
    vector<pair<int, int>>& dependencies,
    vector<int>& duration
) {
  vector<int> ret;
  vector<int> indegree(n, 0);
  vector<long long> end_time(n, 0);
  vector<vector<int>> graph(n);
  queue<int> q;

  for(auto [v1, v2]: dependencies) {
    indegree[v2]++;
    graph[v1].push_back(v2);
  }

  for(int index = 0; index < n; index++) {
    if(indegree[index] == 0) {
      q.push(index);
      end_time[index] = duration[index];
    }
  }

  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    ret.push_back(cur);

    for(auto adj: graph[cur]) {
      indegree[adj]--;
      if(end_time[adj] < end_time[cur] + duration[adj]) end_time[adj] = end_time[cur] + duration[adj];
      if(indegree[adj] == 0) q.push(adj);
    }
  }

  if(ret.size() != n) {
    return -1;
  }

  long long mx = 0;
  
  for(auto cur: end_time) {
    if(mx < cur) mx = cur;
  }

  return mx;
}