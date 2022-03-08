//前缀和+贪心 时间复杂度为o(n)//前缀和 + 暴力枚举时间复杂度为O(n2)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
int arr[maxn];
int minn = 0x7fffffff;
inline int read() {
    char c= getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n;
    n = read();
    for (int i = 1; i <= n; i++) {
        arr[i] = read();
        arr[i] += arr[i - 1];
    }
    int res = -0x7fffffff;
    //arr[r] - arr[l - 1];r >= l;

    /* 
    //前缀和 + 暴力枚举时间复杂度为O(n2)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++){
            res = max(res, arr[i] - arr[j - 1]);
        }
    }
    printf("%d", res); 
    */
   //arr[r] - arr[l - 1]
    //贪心算法，最大值减去最小值即是这个区间最大值
    /* for (int i = 0; i < n; i++) {
        int j = i + 1;
        minn = min(minn, arr[i]);
        res = max(res, arr[j] - minn);
    } */
    //贪心算法，最大值减去最小值即是这个区间最大值
    for (int i = 1; i <= n; i++) {
    //当时卡在了minn = min(minn, arr[i])上了
        minn = min(minn, arr[i - 1]);
        res = max(res, arr[i] - minn);
    }
    printf("%d", res);
    return 0;
}