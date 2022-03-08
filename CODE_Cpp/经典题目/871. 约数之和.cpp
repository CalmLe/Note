#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
unordered_map<int,int>primes;
typedef long long ll;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n, x;
    n = read();
    for (int i = 0; i < n; i++) {
        x = read();
        for (int i = 2; i <= x / i; i++) {
            while(x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if(x > 1) primes[x]++;
    }
    ll res = 1, t = 1;
    for (auto c : primes) {
        t = 1;
        for (int i = 0; i < c.second;i++) t = (t * c.first + 1) % mod;
        res = res * t % mod;
    }
    printf("%lld", res);
    return 0;
}
