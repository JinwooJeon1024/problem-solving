#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> func(int len, int k) {
  if(len == 2 && k == 0) {
    return {{1, -1}};
  }

  if(k-1 )
  auto v1 = func(len-1, k-1);
  auto v2 = func(len-1, k+1);
}

vector<string> generateParenthesis(int n) {
  vector<vector<int>> v = func(2*n, 0);
  vector<string> ans;

  for(auto& c: v) {
    string s;

    for(auto& d: c) {
      if(d == 1) s.push_back('(');
      else if(d == -1) s.push_back(')');
    }

    ans.push_back(s);
  }

  return ans;
}