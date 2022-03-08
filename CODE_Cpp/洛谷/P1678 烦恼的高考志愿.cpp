//注意二分的边界
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 20;
int stu[maxn], uni[maxn];
LL res;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int m, n;
    m = read(), n = read();
    for (int i = 1; i <= m; i++) uni[i] = read();
    for (int i = 1; i <= n; i++) stu[i] = read();
    sort(uni + 1, uni + m + 1);
    /* for (int i = 1; i <= m; i++) printf("%d ", uni[i]); */
    for (int i = 1; i <= n; i++) {
        auto idx = lower_bound(uni + 1, uni + m + 1, stu[i]) - uni;
        //printf("%d ", idx);
        if(stu[i] > uni[m]) res += stu[i] - uni[m];
        else if(stu[i] < uni[1]) res += uni[1] - stu[i];
        else if(idx == 1) res += uni[1] - stu[i];
        else res += min(uni[idx] - stu[i], stu[i] - uni[idx - 1]);
        //printf("%lld\n",res);
    }
    printf("%lld\n",res);
    return 0;
}