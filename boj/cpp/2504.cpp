#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    stack <char> st;
    int ans = 0, num = 1;

    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(s[i]);
            num *= 2;
        }
        else if(s[i] == '['){
            st.push(s[i]);
            num *= 3;
        }
        else if(s[i] == ')'){
            if(st.empty() || st.top() == '['){
                cout << 0;
                return;
            }
            if(s[i-1] == '(') ans += num;
                st.pop();
                num /= 2;
            
        }
        else if(s[i] == ']'){
            if(st.empty() || st.top() == '('){
                cout << 0;
                return;
            }
            if(s[i-1] == '[') ans += num;
                st.pop();
                num /= 3;
            
        }

    }
    if(!st.empty()){
        cout << 0;
        return;
    }
    else cout << ans;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}