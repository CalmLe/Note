#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(int a, int b, ll &x, ll &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    ll d;
    d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    //ll d, x1, y1;
    //d = exgcd(b, a % b, x1, y1);
    //x = y1, y = x1 - (a / b) * y1;
    return d;     
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while(cin >> a >> b) {
        ll x, y;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}