#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(; !isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(; isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
bool prime[maxn]