#include<bits/stdc++.h>
using namespace std;

vector<int> deployOrder(
    int n,
    vector<pair<int, int>>& dependencies
) {
  vector<int> ret;
  vector<int> indegree(n, 0);
  vector<vector<int>> graph(n);
  queue<int> q;

  for(auto [v1, v2]: dependencies) {
    indegree[v2]++;
    graph[v1].push_back(v2);
  }

  for(int index = 0; index < n; index++) {
    if(indegree[index] == 0) q.push(index);
  }

  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    ret.push_back(cur);

    for(auto adj: graph[cur]) {
      indegree[adj]--;
      if(indegree[adj] == 0) q.push(adj);
    }
  }

  if(ret.size() != n) {
    ret.clear();    
  }

  return ret;
}