#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int stone[maxn];
int L, N, M, l, r;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
inline bool check(int x) {
    int amt = 0, now = 0;
    //模拟跳石头,now这个变量表示当前这个人所在的位置
    for (int i = 1; i <= N + 1; i++) {
        if(stone[i] - stone[now] < x) amt++;
        else now = i;
    }
    return amt <= M;
}
int find() {
    l = 0 - 1, r = 1e9 + 1;
    while(l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(void) {
    L = read(), N = read(), M = read();
    for (int i = 1; i <= N; i++) stone[i] = read();
    //这一步很重要
    stone[N + 1] = L;
    printf("%d\n", find());
    return 0;
}