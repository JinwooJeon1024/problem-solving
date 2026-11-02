#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<unordered_set>

using namespace std;

char firstrepeatedchar(const string& s) {
    unordered_set<char> st;

    for(const char& c: s) {
      if(st.find(c) != st.end()) {
        return c;
      }
      
      st.insert(c);
    }
}
