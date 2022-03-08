#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>primes;
typedef long long ll;
const int mod = 1e9 + 7;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
inline void get_divisor(int n) {
    for (int i = 2; i <= n / i; i++) {
        while(n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    if(n > 1) primes[n]++;
    return;
}
int main(void) {
    int n, x;
    n = read();
    for (int i = 0; i < n; i++) {
        x = read();
        get_divisor(x);
    }
    ll res = 1;
    for (auto a : primes)  res = res * (a.second + 1) % mod;
    printf("%lld\n",res);
    return 0;
}