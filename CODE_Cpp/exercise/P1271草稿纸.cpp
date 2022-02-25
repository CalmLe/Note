#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000 + 10;
int n, m;
int arr[maxn];
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        for (int i = 1; i <= m; i++) cin >> arr[i];
        sort(arr + 1, arr + m + 1);
        for (int i = 1; i <= m; i++) cout << arr[i] << " ";
    }
    return 0; 
}