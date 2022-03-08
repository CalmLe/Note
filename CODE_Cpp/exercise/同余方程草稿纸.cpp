#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar())  s = (s << 3) + (s << 1) + (c ^ 48);
    return  s * w;
} 
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    ll gcd, x1, y1;
    gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - (a / b) * y1;
    return gcd;
}
int main(void) {
    ll n, a, b, m;
    n = read();
    while(n--) {
        a = read(), b = read(), m = read();
        ll x, y;
        if(m % exgcd(a, b, x, y) != 0) printf("impossible\n");
        else printf("%lld\n",x);
    }
    return 0;
}