#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int arr[maxn];
int n, cnt;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-')  w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 1) + (s << 3) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    while (cin >> n) {
        ios::sync_with_stdio(false);
        for (int i = 0; i < n; i++) {
            arr[read()]++;
        }
        for (int i = 1; i <= 1000; i++) {
            if (arr[i] != 0) {
                cnt++;
                arr[i] = 1;
            }
        }
        cout << cnt << endl;
        for (int i = 1; i <= 1000; i++)
            if(arr[i] != 0) cout << i << " ";
    }
    return 0;
}
