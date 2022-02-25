#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+ 10;

int arr[N];

int min (int a, int b) {
    return (a <= b) ? a : b;
}
int main(void) {
    int n;
    while (cin >> n) {
        arr[0] = 0;
        int result = -100000000;
        int minn =  100000000;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }   
        for (int i = 1; i <= n; i++) {
            minn = min(minn,arr[i - 1]);
            result = max(result, arr[i] - minn);
        }
        cout << result << endl;
    }
    return 0;
}