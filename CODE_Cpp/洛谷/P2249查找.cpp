#include <bits/stdc++.h>
using namespace std;
const int maxn1 = 1e6 + 10, maxn2 = 1e5 + 10;
int n, m;
int arr[maxn1], ask[maxn2];
/* bool check(int arr[], int mid, int target) {
    return arr[mid] < target;
}
int binary_search(int arr[], int target) {
    int l = -1, r = n; 
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(arr, mid, target)) l = mid;
        else r = mid;
    }
    if (r < n && arr[r] == target) return r + 1;
    return -1;
    
} */
int main(void) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> ask[i];
    /* int j = 0;
    while (m--) {
        cout << binary_search(arr, ask[j])  << " ";
        j++;
        
    } */
    int j = 0;
    while (m--){
        int a = lower_bound(arr, arr + n, ask[j]) - arr;
        if (arr[a] == ask[j]) cout << a + 1;
        else cout << -1;
        cout << " ";
        j++;
    }
}