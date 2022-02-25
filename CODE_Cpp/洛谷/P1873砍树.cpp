#include <bits/stdc++.h>
using namespace std;
const int maxn1 = 1e6 + 10;
int n,m; 
int arr[maxn1];
bool check(int l, int mid) {
    
}
int find (int a) {
    int l = 0; r = 0x7fffffff;
    int mid = l + r >> 1;
    while(l + 1 < r) {
        if (check(l,mid)) l = mid;
        else r = mid;
    } 
    return mid; 
}
int main(void) {
    ios::sync_with_stdio(false);
  
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        
        

    }
}
