#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL horner(int x, int arr[], int n) {
    LL res = arr[n];
    for (int i = n; i >= 1; i++) {
        res = res * x +arr[i - 1];
    }
    return res;
}
int mai(void) {
    int arr[] = {1,2,3,4};
    cout << horner(1, arr, 3) << endl;
    return 0;
}