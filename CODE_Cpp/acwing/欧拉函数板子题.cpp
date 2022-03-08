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
int main(void) {
    int  n; 
    ll res;
    n = read();
    while(n--) {
        int x = read();
        res = x;
        for (int i = 2; i <= x / i; i++) {
            if(x % i == 0) {
                while(x % i== 0) {
                    x /= i;
                }
//   res *= (i - 1) / i， res *= (1 - 1 / i);这两种写法都是错的结果都会为0； 
                res = res * (i - 1) / i;
            }
        }
        if(x > 1) res = res * (x - 1) / x;
        printf("%lld\n",res);
    }
    return 0;
}