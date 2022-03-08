#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int arr[maxn];
typedef long long ll;
int gcd(int a, int b){
    return b ? gcd(b , a % b) : a;
}
int lcm(int a, int b) {
    return a  / gcd(a,b) * b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        ll res = arr[0];
        for (int i = 1; i < n; i++) {
            res = lcm(res, arr[i]);
        }
        cout << res << endl;
    }
}