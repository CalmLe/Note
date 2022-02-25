#include <bits/stdc++.h>

using namespace std;

const int N = 10e5 + 10;

int arr[N],b[N];

void insert(int l, int r, int c) {
     b[l] += c;
     b[r + 1] -= c;
}

int main(void) {
    int n, m;
    cin>> n >> m;
    
    for (int i = 1; i <= n ;i++) cin >> arr[i];
    
    //这个初始化很秒,用差分的思路直接给前缀和数组给值
    for (int i = 1; i <= n; i++) insert(i,i,arr[i]);
    
    int l, c, r;
    
    while (m--) {
        cin>> l >> r >> c;
        insert(l, r, c);
    }
    
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    
    for (int i = 1; i <= n; i++) cout<< b[i]<<" "; 
    
    return 0;
}