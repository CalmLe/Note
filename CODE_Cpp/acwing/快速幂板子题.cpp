#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (; !isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (; isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
//这里要主要，函数的参数不能定义成int类型，超过了题目给的数据范围
ll qmi(ll a,ll k, ll p) {
    ll res = 1;
    while(k) {
        if(k & 1) res = res * a % p ;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}
int main(void) {
    int n, a, b, p;
    n = read();
    while(n--) {
        a = read(), b = read(), p = read();
        printf("%lld\n",qmi(a,b,p));
    }
    return 0;
}