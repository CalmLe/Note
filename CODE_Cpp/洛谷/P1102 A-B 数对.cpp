//裸裸的二分
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
LL cnt;
int arr[maxn];
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n, c;
    n = read();
    c = read();
    for (int i = 0; i < n; i++) {
        arr[i] = read();
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int b = arr[i], first, last;
        //这里不需要做特殊判断 若是没有等于b + c的元素， last - first = 0对结果没有影响
        if(lower_bound(arr, arr + n, b + c) - arr != n) {
            first = lower_bound(arr, arr + n, b + c) - arr;
            last = upper_bound(arr, arr + n, b + c) -arr - 1;
            cnt += last - first + 1;
        }
    }
    printf("%lld", cnt);
    return 0;
}