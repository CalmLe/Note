#include <bits/stdc++.h>

using namespace std;

const int N = 10e5 + 10;

int arr[N], s[N];

int main(void) {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + arr[i];   
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout<< s[r] - s[l - 1]<<endl;
    }
    return 0;
}