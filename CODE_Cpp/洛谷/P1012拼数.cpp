#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
string arr[maxn];
/* inline int read() {
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
} */
bool cmp(string a, string b) {
    return a + b > b + a;
}
int main(void) {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) cout << arr[i]; 
    return 0;
}