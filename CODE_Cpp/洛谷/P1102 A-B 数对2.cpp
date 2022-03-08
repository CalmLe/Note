#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL res;
unordered_map<int,LL>b;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return w * s;
}
int main(void) {
    int n, c, x;
    n = read(), c = read();
    for (int i = 0; i < n; i++) {
        x = read();
        b[x]++;
    }
    /* for (auto item : b) {             3 1 1 2 2 1
        printf("%d %d\n",item.first, item.second);
    } */
    for(auto item : b) {
        auto itor = b.find(item.first + c);
        if(itor != b.end()) res += itor->second * item.second;
        //printf("%lld\n", res);
    }
    printf("%lld", res); 
    return 0;
}