#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 10;
string arr[maxn];
bool cmp(string s1, string s2){
    return (s1 + s2) >= (s2 + s1);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) cout << arr[i];
    cout << endl;
    return 0;
}