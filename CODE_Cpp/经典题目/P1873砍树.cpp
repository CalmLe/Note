//发现锯的高度越高，得到木材的总量越少，所以可以用二分去做
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
LL M;
int tree[maxn], N, H;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
bool check(int mid) {
    LL sum = 0;
    for(int i = 0; i < N; i++) {
        if(mid < tree[i]) sum += tree[i] - mid;
    }
    return sum >= M; 
}
int find() {
    int l = -1, r = 1e9;
    while(l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;

}
int main(void) {
    N = read(), M = read();
    for(int i = 0; i < N; i++) tree[i] = read();
    printf("%d\n", find());
    return 0;
}