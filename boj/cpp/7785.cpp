#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;


int n;
unordered_set<string> people;

int main(void) {
  cin >> n;

  while (n--) {
      string name, state;
      cin >> name >> state;

      if (state == "enter")
          people.insert(name);
      else
          people.erase(name);
  }

  vector<string> ans(people.begin(), people.end());

  sort(ans.begin(), ans.end(), greater<string>());

  for (const string& name : ans)
      cout << name << '\n';

}
