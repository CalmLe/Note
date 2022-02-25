#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int arr[N], a[N], b[N], c[N], idx[N];

int main(void) {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= m; m++) cin >> idx[i];
        int j = 0 ,flag = 0;
        while ((m - 1)--) cin >> a[j++] >> b[j++] >> c[j++];
        for (int i = 1; i <= m - 1; i++) {
            if(i == 2 || i == 8) arr[i] += a[i];
            else {
                if (flag == 0 ) {
                    arr[i] += b[i] + c[i];
                    flag++;
                }
                arr[i] += b[i];
            }
        }
        unsigned long long result = 0;
        for (int i = 1; i < m; i++) {
            result += arr[idx[i + 1] - idx[i]];
        }
        cout << result <<endl;
    }
    return 0;
}