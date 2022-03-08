//贪心 时间复杂度O(n)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
int sum[maxn];
int res = -0x7fffffff;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
        temp += sum[i];
        if(temp > res) res = temp;
        //res = max(res, sum[i]);
        if(temp < 0) temp = 0;
    }
    cout << res << endl;
    return 0;
}