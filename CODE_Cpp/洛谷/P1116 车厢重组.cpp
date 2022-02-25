//本题的思路就是冒泡模拟，算出逆序数，但也可以用更好的方法，归并排序求逆序数
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int arr[maxn], temp[maxn];
int cnt = 0;
void merge_sort(int arr[], int l, int r) {
    if (l >= r) return ;
    int mid = (r - l >> 1) + l;
    merge_sort(arr, l ,mid);
    merge_sort(arr, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++,i++;
        }else{
            temp[k] = arr[j];
            k++, j++;
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        k++, i++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        k++, j++;
    }
    for (int i = l, j = 0; i <= r; i++, j++) arr[i] = temp[j];
} 
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    int n; 
    while (cin >> n) {
        for (int i = 0; i < n; i++) arr[i] = read();
        merge_sort(arr, 0, n - 1);
        cout << cnt << endl;
    }
    return 0;
}