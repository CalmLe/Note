#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int stk[maxn], tt, n;
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (register int i = 0; i < n; i++) cin >> stk[i];
    for (register int i = 0; i < n; i++) {
        bool flag = true;
        for (register int j = i - 1; j >=0 ; j--) {
            if (stk[j] < stk[i]) {
                flag = false;
                cout << stk[j] << " ";
                break;
            }
        }
        if (flag) cout << -1 << " ";
        
    }
    return 0;
}