
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    stack <char> st;
    int ans = 0, num = 0;

    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            st.pop();

            if(s[i-1] == '(') {
              ans += st.size();
            }
            else {
              ans++;
            }
        }

    }

    cout << ans;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}