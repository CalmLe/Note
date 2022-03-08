//map 映照容器
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int b[maxn];
map<int,int> a;
LL res;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n, c;
    n = read(), c = read();
    for (int i = 0; i < n; i++) {
        b[i] = read();
        a[b[i]]++;
    }   
    for (int i = 0; i < n; i++) {
        if(a[b[i] + c] != 0) res += a[b[i] + c];
    }
    printf("%lld",res);
    return 0;
}