/*
模板：
inline void insert(int l, int r, int x) {
    b[l] += x;
    b[r + 1] -=x;
    return;
}
初始化 insert(i, i, x);
插入值 insert(i, j, x);
最后扫一遍 b[i] += b[i - 1];
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
//s位原数组,b为差分数组
int s[maxn], b[maxn];
inline void insert( int l, int r, int x) {
    b[l] += x;
    b[r + 1] -=x;
    return;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++) cin >> s[i];
     //差分数组初始化，很妙啊
    for (int i = 1; i <= n;i++) insert(i, i, s[i]);
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
     //别忘了最后累加一遍
    for (int i = 1; i <= n;i++) {
        b[i] += b[i - 1];
        cout << b[i] << " ";
    }
    return 0;
}