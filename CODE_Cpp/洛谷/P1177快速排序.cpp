/* #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];
int n;
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        
    }
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int arr[maxn], temp[maxn];
int n;
void merge_sort(int a[], int l, int r) {
    if (l + 1 > r) return ;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        }else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= r) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];
    return ;
}
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        merge_sort(arr, 0, n - 1);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    return 0;
}