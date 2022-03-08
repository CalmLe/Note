#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qmi(LL a, LL k, LL p) {
    LL res = 1;
    while(k) {
        if(k & 1) res =  res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        LL a, p;
        cin >> a >> p;
        if(a % p == 0) cout << "impossible" << endl;
        else cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}