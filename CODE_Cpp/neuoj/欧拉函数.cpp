#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(int n) {
    ll res = n;
    for (int i = 2; i <= n / i; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i; 
            }
            res = res * (i - 1) / i;
        }
    }
    if(n > 1) res = res * (n - 1) / n;
    return res;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n) {
        cout << phi(n) << endl;
    }
    return 0;
}