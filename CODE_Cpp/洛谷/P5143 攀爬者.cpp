#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
typedef struct point {
    int x;
    int y;
    int z;
};
point p[maxn];
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while(!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    } 
    return s * w;
}
bool cmp (point p1, point p2) {
    return p1.z > p2.z;
}
int main(void) {
    int n = read();
    for (register int i = 0 ; i < n; i++) {
        p[i].x = read();
        p[i].y = read();
        p[i].z = read();
    }
    sort(p, p + n, cmp);
    double ans = 0;
    for (register int i = 1; i < n; i++) {
        ans += sqrt((p[i].x - p[i - 1].x) * (p[i].x - p[i - 1].x) + (p[i].y - p[i - 1].y) * (p[i].y - p[i - 1].y) + (p[i].z - p[i - 1].z) * (p[i].z - p[i - 1].z));
    } 
    printf("%.3lf", ans);
}