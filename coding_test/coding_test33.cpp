#include <bits/stdc++.h>
using namespace std;

// ====================================
// Directed Graph Cycle Detection
// ====================================

bool hasCycle(int n, const vector<pair<int,int>>& edges) {
  queue<int> q;
  vector<vector<int>> graph(n);
  vector<int> indegree(n, 0);
  vector<int> ret;

  for(auto [u, v]: edges) {
    indegree[v]++;
    graph[u].push_back(v);
  }

  for(int i = 0; i < n; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    auto cur = q.front(); q.pop();

    for(auto adj: graph[cur]) {
      indegree[adj]--;
      if(indegree[adj] == 0) q.push(adj);
    }

    ret.push_back(cur);
  }

  return ret.size() != n;
}


// ====================================
// Tests
// ====================================

int main() {
    // Test 1: 단순 DAG
    assert(!hasCycle(4, {
        {0,1}, {0,2}, {1,3}, {2,3}
    }));

    // Test 2: 단순 사이클
    assert(hasCycle(3, {
        {0,1}, {1,2}, {2,0}
    }));

    // Test 3: 연결되지 않은 컴포넌트에 사이클
    assert(hasCycle(6, {
        {0,1}, {1,2},
        {3,4}, {4,5}, {5,3}
    }));

    // Test 4: Self-loop
    assert(hasCycle(3, {
        {0,0}, {0,1}, {1,2}
    }));

    // Test 5: 사이클 없는 복잡한 그래프
    assert(!hasCycle(5, {
        {0,1}, {0,2},
        {1,3}, {2,3},
        {3,4}
    }));

    // Test 6: 양방향 간선
    assert(hasCycle(2, {
        {0,1}, {1,0}
    }));

    // Test 7: 간선 없는 그래프
    assert(!hasCycle(5, {}));

    // Test 8: 빈 그래프
    assert(!hasCycle(0, {}));

    // Test 9: 긴 경로 중간에 사이클
    assert(hasCycle(6, {
        {0,1}, {1,2}, {2,3},
        {3,4}, {4,2}, {4,5}
    }));

    cout << "All tests passed!\n";
    return 0;
}
