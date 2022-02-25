#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
int n, m, temp;
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        while (m--) {
            cin >> temp;
            arr[temp]++;
            
        }
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0) {
                continue;
            }else{
                for (int j = 0; j < arr[i]; j++) cout << i <<" ";
            }
        }
    }
    return 0;
}