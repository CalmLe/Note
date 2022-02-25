#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int arr[maxn], stk[maxn], ans[maxn], tt = 0;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while(!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    int n = read();
    for (register int i = 1; i <= n ; i++) arr[i] = read();
    for (register int i = n; i >= 0 ; i--) {
        while (tt && arr[stk[tt]] <= arr[i]) tt--;
        if (!tt) ans[i] = 0;
        else ans[i] = stk[tt];
        stk[++tt] = i; 
    }
    for (register int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}