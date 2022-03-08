#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cnt, temp;
const int maxn = 2e5 + 10;
int arr[maxn], n, x;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1)  + (c ^ 48);
    return s * w;
}
int main(void) {
    n = read(), x = read();
    for(int i = 0; i < n; i++) arr[i] = read();
    //其实这里还可以优化一下的，只需要处理第一组，因为后面的话只要前面满足就不会满足arr[i] >= temp的，只可能arr[i] + arr[i - 1] > x
    for(int i = 1; i < n; i++) {
        if(arr[i] + arr[i - 1] > x) {
            temp = arr[i] + arr[i - 1] - x;
            cnt += temp;
            if(arr[i] >= temp) arr[i] -= temp;
            else arr[i] = 0;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}