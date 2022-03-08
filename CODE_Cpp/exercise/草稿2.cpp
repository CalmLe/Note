#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
>>>>>>x表示多项式的x,数组arr[]储存x前面的系数，n表示最高次
>>>>>>要千万要注意下标防止出现数组越界的情况
*/
LL horner(int x, int arr[], int n) {
    LL res = arr[n];
    for (int i = n; i >= 1; i--) {
        res = res * x +arr[i - 1];
    }
    return res;
}
int main(void) {
    int arr[1000];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    cout << horner(1, arr, 3) << endl;
    return 0;
}