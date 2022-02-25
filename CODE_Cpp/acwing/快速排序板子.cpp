#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];
int n;
void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;
    int x = arr[(r - l >> 1) + l];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (arr[++i] < x);
        while (arr[--j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j + 1);
    quick_sort(arr, j, r);
    return;
}
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        quick_sort(arr, 0, n - 1);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    return 0;
}