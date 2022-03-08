#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int mod = 1e9 + 7;
// a 底数 k 为幂 p 为mod
ll qmi(ll a, ll k, ll p) { 
    ll res = 1; 
    while(k) {
        if(k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    while(cin >> m >> n) {
        cout << qmi(m, n, mod);
    }
    return 0;
}