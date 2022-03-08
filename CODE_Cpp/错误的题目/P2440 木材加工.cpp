//发现要是长度越长的话，越达不到根数的要求,也就是说长度跟根数成反比
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int MAX = 1e8;
int length[maxn];
int n, k, amt;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
bool check(int x) {
    amt = 0;
    for (int i = 0; i < n; i++) {
         amt += length[i] / x;
    }
    return amt >= k;
}
int find() {
    int l = -1, r = MAX;
    while(l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if(check(mid)) l = mid;
        else r = mid;
        //printf("%d ", r);
    }
    //if(l == -1) return 0;
    return l;
}
int main(void) {
    n = read(), k = read();
    for (int i = 0; i < n; i++) length[i] = read();
    //find();
    printf("%d", find());
    return 0;
}