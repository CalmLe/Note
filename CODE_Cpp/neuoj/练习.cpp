#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int stk[maxn], tt;
int m, x;
string s;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    m = read();
    while (m--) {
        scanf("%s", s);
        printf("%s\n",s);
        if (s == "push") {
            x = read();
            stk[++tt] = x;
        }
        else if(s == "pop") tt--;
        else if (s == "empty"){
            if (tt > 0) printf("NO\n");
            else printf("YES\n");
        }
        else{
            printf("%d\n", stk[tt]);
        }
    }
}

