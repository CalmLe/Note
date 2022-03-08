#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
//m表示借的金额，y表示每个月需要支付的金额，t表示需要还的月份
int m, y, t;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
inline bool check(double x) {
    double a = m;
    //秦久韶算法
    for (int i = 1; i <= t; i++) {
        a = a * (1 + x) - y;
    }
    if(a > 0) return false; 
    return true;
    
}
//因为月利率是单调的，所以可以对月利率进行二分
double find() {
    double l = 0, r = 10;
    while(r - l > eps) {
        double mid = (r + l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(void) {
    m = read(), y = read(), t = read();
    //printf("%d %d %d", m, y, t);
    printf("%.1lf", find() * 100);
    return 0;
}
