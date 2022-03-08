//dp 时间复杂度为O(n)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
int arr[maxn],dp[maxn];
int res = -0x7fffffff;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        /*
        第一个数为一个有效序列
        如果一个数加上上一个有效序列得到的结果比这个数大，那么该数也属于这个有效序列。
        如果一个数加上上一个有效序列得到的结果比这个数小，那么这个数单独成为一个新的有效序列
        */
        //这里的dp可以进行优化，因为只有dp[i] 跟dp[i - 1]
        if(i == 1)  dp[i] = arr[i];
        else dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res = max(res, dp[i]);
        
    }
    cout << res << endl;
    return 0;
}
