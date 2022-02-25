#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int arr[maxn];
int lowbits(int n) {
    return (n & (-n));
}
int main(void) {
    int n,cnt = 0;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cnt = 0;
            cin >> arr[i];
            while (arr[i]) {
                arr[i] -= lowbits(arr[i]);
                cnt++;
            }
            cout << cnt << " ";
        }
        
    }
    return 0;
}