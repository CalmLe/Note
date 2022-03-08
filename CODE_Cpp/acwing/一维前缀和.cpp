//核心 s[i] = s[i - 1] + a[i];
//其实可以优化成arr[i] += arr[i - 1];
//注意建议下标从1开始arr[0] = 0 所以不会对递推公式产生影响，这样就不需要特殊特判一下了，否则需要if特判一下
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];
int n, m;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
    return 0;
}