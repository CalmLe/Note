#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int arr[maxn];
int N,M,cnt;
LL res, l = -0x7fffffff,r;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
inline int max(LL a, LL b) {
    return (a >= b) ? a : b;
}
inline bool check(int x) {
    //  小细节这里得从1开始而不是0;
    res = 0,cnt = 1;
    for (int i = 0; i < N; i++) {
        if(res + arr[i] <= x) res += arr[i];
        else res = arr[i], cnt++;
    }
    return cnt > M;
}
inline int find() {
    l = l - 1, r = r + 1;
    while(l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return r;
}
int main(void) {
    N = read(), M = read();
    for (int i = 0; i < N; i++) {
        arr[i] = read();
        l = max(l, arr[i]);
        r += arr[i];
    }
    printf("%d",find());
    return 0;
}