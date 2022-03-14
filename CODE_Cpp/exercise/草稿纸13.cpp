#include <bits/stdc++.h>
using namespace std;
const int mod = 2003;
int arr[mod], x, n, null = 0x3f3f3f3f;
inline int find(int x) {
    int k = (x % mod + mod) % mod;
    while(arr[k] != null && arr[k] != x) {
        k++;
        if(k == mod) k = 0;
    }
    return k;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 0; i < n; i++) {
        cin >> x;
        x = find(x);
        //printf("%d ",arr[x]);
        //printf("%d ",x);
        if(arr[x] != 0x3f3f3f3f) arr[x]++;
        else arr[x] = 2;
    }
    for (int i = 0; i < mod; i++) {
        if(arr[i] != 0x3f3f3f3f) cout << arr[i] << " ";
    }
    return 0;
}