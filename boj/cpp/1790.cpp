#include<bits/stdc++.h>
using namespace std;

int n, k, p, q, m;
int solve(int n, int k){
    p = 1, q = 9;
    while(true){
        if(k < p*q)
            break;
        k -= p*q;
        p++;
        q *= 10;
    }
    int i = 1;
    for(int j = 0; j < p - 1 ; j++)
        i *= 10;

    if(k % p == 0)
        m = i + k / p - 1; 
    else
        m = i + k / p;
    if(n < m) return -1;
    int cnt = k % p ? p - k % p + 1 : 1; // cnt는 m에서 오른쪽에서 cnt번째에 있다
    // cout << "p: " << p << ", k: " << k << ", m: " << m << ", cnt: " << cnt << '\n';
    while(true){
        if(cnt == 1){
            return m % 10;
        }
        else{
            cnt--;
            m = m / 10;
        }
    }
    return -2;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    cout << solve(n, k);
    return 0; 
}